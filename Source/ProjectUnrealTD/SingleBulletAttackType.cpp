#include "SingleBulletAttackType.h"
#include "Public/Tower.h"
#include "Baddies.h"

// Définit les valeurs par défaut
ASingleBulletAttackType::ASingleBulletAttackType()
{
	// Définissez ce actor pour appeler Tick() à chaque frame. Vous pouvez désactiver cette option pour améliorer les performances si vous n’en avez pas besoin.
	PrimaryActorTick.bCanEverTick = true;
}

// Appelé au début du jeu ou au moment de l'apparition de l'animal.
void ASingleBulletAttackType::BeginPlay()
{
	Super::BeginPlay();
}

// Appelé chaque frame
void ASingleBulletAttackType::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASingleBulletAttackType::Attack_Implementation(const TArray<ABaddies*>& BaddiesInRange, const ATower* tower)
{
	/*if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Actor Location: %s"), *tower->BulletStartPoint[0]->GetComponentLocation().ToString()));
	}*/

	ABullet* SpawnedBullet = GetWorld()->SpawnActor<ABullet>(tower->Bullet, tower->BulletStartPoint[0]->GetComponentLocation(), FRotator::ZeroRotator);
	if (BaddiesInRange.Num() > 0)
	{
		ABaddies* FirstBaddie = BaddiesInRange[0];
		AActor* FirstBaddieActor = Cast<AActor>(FirstBaddie);

		if (FirstBaddieActor)
		{
			SpawnedBullet->Setup(FirstBaddieActor);
		}
	}
}