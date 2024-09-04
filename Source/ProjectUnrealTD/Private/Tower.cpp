// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "../Baddies.h"
#include "Components/SphereComponent.h"

// Sets default values
ATower::ATower()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Set default range
    range = 500.0f;

    // Create a sphere component to represent the tower's attack range
    RangeSphere = CreateDefaultSubobject<USphereComponent>(TEXT("RangeSphere"));
    RangeSphere->InitSphereRadius(range);
    RangeSphere->SetCollisionProfileName(TEXT("Trigger"));
    RangeSphere->SetupAttachment(RootComponent);

    // Bind to the overlap event
    RangeSphere->OnComponentBeginOverlap.AddDynamic(this, &ATower::OnEnemyEnterRange);

}

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATower::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATower::ProcessAttack()
{
    // Get all overlapping actors of class Baddie
    TArray<AActor*> OverlappingActors;
    RangeSphere->GetOverlappingActors(OverlappingActors, ABaddies::StaticClass());

    for (AActor* Actor : OverlappingActors)
    {
        ABaddies* Baddie = Cast<ABaddies>(Actor);
        if (Baddie)
        {
            // Implement your attack logic here, e.g., reduce health
            // Baddie->TakeDamage(DamageAmount);
            if (GEngine)
                GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Wassssssuuuup bitconneccccctt !!!"));
        }
    }
}

void ATower::OnEnemyEnterRange(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    // This function is called when an enemy enters the range.
    // You can choose to trigger an attack here or gather data.
    ABaddies* Baddie = Cast<ABaddies>(OtherActor);
    if (Baddie)
    {
        // Call attack or another function
        ProcessAttack();
    }
}