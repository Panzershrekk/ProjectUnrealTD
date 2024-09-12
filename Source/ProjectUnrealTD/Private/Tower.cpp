// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "../Baddies.h"
#include "Components/SphereComponent.h"

// Sets default values
ATower::ATower()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Create a sphere component to represent the tower's attack range
    RangeSphere = CreateDefaultSubobject<USphereComponent>(TEXT("RangeSphere"));
    RangeSphere->InitSphereRadius(range);
    RangeSphere->SetCollisionProfileName(TEXT("Trigger"));
    RangeSphere->SetupAttachment(RootComponent);

    // Bind to the overlap event
    RangeSphere->OnComponentBeginOverlap.AddDynamic(this, &ATower::OnEnemyEnterRange);
    RangeSphere->OnComponentEndOverlap.AddDynamic(this, &ATower::OnEnemyExitRange);

    USceneComponent* NewBulletOrigin = CreateDefaultSubobject<USceneComponent>(TEXT("BulletStartPoint1"));
    NewBulletOrigin->SetupAttachment(RootComponent);
    BulletStartPoint.Add(NewBulletOrigin);

    DummyMuzzle = CreateDefaultSubobject<USceneComponent>(TEXT("DummyMuzzle"));
    DummyMuzzle->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();
    if (AttackType)
    {
        AttackTypeSpawned = GetWorld()->SpawnActor<AActor>(AttackType);

        if (AttackTypeSpawned && AttackTypeSpawned->GetClass()->ImplementsInterface(UIAttackType::StaticClass()))
        {
            IAttackType = Cast<IIAttackType>(AttackTypeSpawned);
        }
        
    }
}

// Called every frame
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    TimeSinceLastAttack -= DeltaTime;
    if (isBaddiesInRange == true && TimeSinceLastAttack <= 0)
    {
        
        TimeSinceLastAttack = fireRate;
        GetBaddiesInRange(BaddiesInRange);

        // Si des ennemis sont trouvés, attaquer
        if (BaddiesInRange.Num() > 0)
        {
            ProcessAttack();
            TimeSinceLastAttack = fireRate;
        }
    }
}

// Called to bind functionality to input
void ATower::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATower::ProcessAttack()
{
	if (IAttackType) // Si le cast réussit
	{
		IAttackType->Attack_Implementation(BaddiesInRange, BulletStartPoint);
        ABullet* SpawnedBullet = GetWorld()->SpawnActor<ABullet>(Bullet, BulletStartPoint[0]->GetComponentLocation(), FRotator::ZeroRotator);

	}
}

void ATower::GetBaddiesInRange(TArray<ABaddies*>& OutBaddies)
{
    // Récupérer tous les acteurs qui se chevauchent avec la RangeSphere
    TArray<AActor*> OverlappingActors;
    RangeSphere->GetOverlappingActors(OverlappingActors, ABaddies::StaticClass());

    // Filtrer les acteurs pour trouver les baddies
    for (AActor* Actor : OverlappingActors)
    {
        ABaddies* Baddie = Cast<ABaddies>(Actor);
        if (Baddie)
        {
            OutBaddies.Add(Baddie);
        }
    }
}


void ATower::OnEnemyEnterRange(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    ABaddies* Baddie = Cast<ABaddies>(OtherActor);
    if (Baddie)
    {
        isBaddiesInRange = true;  // Un ennemi est dans la portée
    }
}

// Appelé lorsque l'ennemi sort de la portée
void ATower::OnEnemyExitRange(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    ABaddies* Baddie = Cast<ABaddies>(OtherActor);
    if (Baddie)
    {
        // Vérifier s'il reste des ennemis dans la portée
        TArray<AActor*> OverlappingActors;
        RangeSphere->GetOverlappingActors(OverlappingActors, ABaddies::StaticClass());

        if (OverlappingActors.Num() == 0)
        {
            isBaddiesInRange = false;  // Aucun ennemi dans la portée
        }
    }
}