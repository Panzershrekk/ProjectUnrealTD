// Fill out your copyright notice in the Description page of Project Settings.


#include "TestSpawner.h"
#include "Baddies.h"

// Sets default values
ATestSpawner::ATestSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestSpawner::SpawnActor()
{
	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	ABaddies* baddie = GetWorld()->SpawnActor<ABaddies>(actorBpToSpawn, GetActorTransform(), spawnParams);
	baddie->SetTarget(target);
}