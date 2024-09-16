// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameManager.generated.h"

UCLASS()
class PROJECTUNREALTD_API AGameManager : public AActor
{
    GENERATED_BODY()

private:
    int32 PlayerGold;

public:
    UFUNCTION(BlueprintCallable, Category = "Gold")
    int32 GetPlayerGold() const { return PlayerGold; }

    // Fonction pour ajouter de l'or
    UFUNCTION(BlueprintCallable, Category = "Gold")
    void AddGold(int32 Amount)
    {
        PlayerGold += Amount;
    }

    AGameManager()
    {
        PlayerGold = 0;
    }

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
};