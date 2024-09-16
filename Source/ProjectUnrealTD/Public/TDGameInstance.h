// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameManager.h"
#include "TDGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTUNREALTD_API UTDGameInstance : public UGameInstance
{
    GENERATED_BODY()

private:
    UPROPERTY()
    AGameManager* GameManager;

public:
    // Getter pour le GameManager
    UFUNCTION(BlueprintCallable, Category = "GameManager")
    AGameManager* GetGameManager() const { return GameManager; }

    // Setter ou fonction pour initialiser le GameManager
    UFUNCTION(BlueprintCallable, Category = "GameManager")
    void SetGameManager(AGameManager* NewManager)
    {
        if (NewManager)
        {
            GameManager = NewManager;
        }
    }
};