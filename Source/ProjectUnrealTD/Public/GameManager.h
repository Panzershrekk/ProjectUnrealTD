// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tower.h"
#include "GameManager.generated.h"

UCLASS()
class PROJECTUNREALTD_API AGameManager : public APlayerController
{
    GENERATED_BODY()

private:
    int32 PlayerGold;
    TSubclassOf<ATower> SelectedTowerClass;
    bool bIsPlacingTower;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnKillPlayerSignature);
public:

    UPROPERTY(BlueprintReadOnly, Category = "Tower")
    ATower* GhostTower;

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

    UFUNCTION(BlueprintCallable, Category = "Tower")
    bool IsTowerBeingPlaced() const { return bIsPlacingTower; }

    UFUNCTION(BlueprintCallable, Category = "Tower")
    void SetBuyableSelectedTower(TSubclassOf<ATower> TowerClass);
    UFUNCTION(BlueprintCallable, Category = "Tower")
    void CancelBuyableTowerSelection();
    UFUNCTION(BlueprintCallable, Category = "Tower")
    void SpawnGhostTower();
    UFUNCTION(BlueprintCallable, Category = "Tower")
    void DespawnGhostTower();

    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnKillPlayerSignature OnSelectTowerToBuy;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

};