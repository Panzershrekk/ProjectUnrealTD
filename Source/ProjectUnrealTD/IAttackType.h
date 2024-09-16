#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IAttackType.generated.h"

// L'interface Blueprintable
UINTERFACE(BlueprintType)
class UIAttackType : public UInterface
{
    GENERATED_BODY()
};

// Classe d'interface (logique)
class IIAttackType
{
    GENERATED_BODY()

public:
    // Expose la fonction Attack aux Blueprints et permet son implémentation
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
    void Attack(const TArray<ABaddies*>& BaddiesInRange, const ATower* tower);
};