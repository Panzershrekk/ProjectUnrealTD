// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "TDGameInstance.h"

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	UTDGameInstance* TDGameInstance = Cast<UTDGameInstance>(GetGameInstance());

	if (TDGameInstance && !TDGameInstance->GetGameManager())
	{
		TDGameInstance->SetGameManager(this);
	}
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
}

void AGameManager::SetBuyableSelectedTower(TSubclassOf<ATower> TowerClass)
{
	if (TowerClass)
	{
		SelectedTowerClass = TowerClass;
		bIsPlacingTower = true;

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("TOWER IS SET")));
	}
}

void AGameManager::CancelBuyableTowerSelection()
{

	SelectedTowerClass = NULL;
	bIsPlacingTower = false;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("TOWER IS RESET")));
}

void AGameManager::SpawnGhostTower(TSubclassOf<ATower> TowerClass)
{
	if (TowerClass)
	{
		GhostTower = GetWorld()->SpawnActor<ATower>(TowerClass, FVector::ZeroVector, FRotator::ZeroRotator);
		if (GhostTower)
		{
			GhostTower->SetActorEnableCollision(false);
			//GhostTower->SetTransparency(true);
		}
	}
}