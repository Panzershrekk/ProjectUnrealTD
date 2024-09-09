#include "SingleBulletAttackType.h"

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

void ASingleBulletAttackType::Attack_Implementation(const TArray<ABaddies*>& BaddiesInRange)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("I need more boulettes !!!"));
}