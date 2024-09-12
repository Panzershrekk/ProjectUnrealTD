#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IAttackType.h"
#include "SingleBulletAttackType.generated.h"

UCLASS(Blueprintable)
class PROJECTUNREALTD_API ASingleBulletAttackType : public AActor, public IIAttackType
{
    GENERATED_BODY()

public:
    // Définit les valeurs par défaut des propriétés de ce actor
    ASingleBulletAttackType();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float blipbloop;

protected:
    // Appelé au début du jeu ou au moment de l'apparition de l'acteur
    virtual void BeginPlay() override;

public:
    // Appelé chaque frame
    virtual void Tick(float DeltaTime) override;

    // Implémentation de l'attaque
    virtual void Attack_Implementation(const TArray<ABaddies*>& BaddiesInRange, const TArray<USceneComponent*>& BulletsStartPoints) override;
};
