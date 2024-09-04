// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestSpawner.generated.h"

UCLASS()
class PROJECTUNREALTD_API ATestSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestSpawner();

	UFUNCTION(BlueprintCallable, Category = "Spawner")
		void SpawnActor();

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> actorBpToSpawn;
	UPROPERTY(EditAnywhere)
		AActor* target;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
