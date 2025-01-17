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
	OnSelectTowerToBuy.Broadcast();
}


void AGameManager::CancelBuyableTowerSelection()
{

	SelectedTowerClass = NULL;
	bIsPlacingTower = false;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("TOWER IS RESET")));
	OnSelectTowerToBuy.Broadcast();
}

void AGameManager::SpawnGhostTower()
{
	if (SelectedTowerClass)
	{

		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn; // To make it spawnable on other collider, default won't spawn if it collide

		GhostTower = GetWorld()->SpawnActor<ATower>(SelectedTowerClass, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
		if (GhostTower)
		{
			GhostTower->SetActorEnableCollision(false);
			//GhostTower->SetTransparency(true);
		}
	}
}

void AGameManager::DespawnGhostTower()
{
	if (GhostTower)
	{
		GhostTower->Destroy();
		GhostTower = nullptr;
	}
}

void AGameManager::BuyAndSpawnSelectedTower(FVector location, FRotator rotation)
{
	if (SelectedTowerClass)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		GetWorld()->SpawnActor<ATower>(SelectedTowerClass, location, rotation, SpawnParams);
	}
}