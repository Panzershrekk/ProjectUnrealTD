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
}