// Fill out your copyright notice in the Description page of Project Settings.


#include "Baddies.h"

// Sets default values
ABaddies::ABaddies()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABaddies::ChangeLife(int lifeDifferenceValue)
{
	life -= lifeDifferenceValue;
	if (life <= 0)
	{
		Kill();
	}
}

void ABaddies::Kill()
{
	Destroy();
}

// Called when the game starts or when spawned
void ABaddies::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaddies::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (targetToMove)
	{
		FVector CurrentLocation = GetActorLocation();
		FVector TargetLocation = targetToMove->GetActorLocation();
		FVector Direction = (TargetLocation - CurrentLocation).GetSafeNormal();
		double Distance = FVector::Dist(TargetLocation, CurrentLocation);
		FVector NewLocation = CurrentLocation + (Direction * moveSpeed * DeltaTime);
		SetActorLocation(NewLocation);
		if (Distance <= 1)
		{
			Kill();
		}
	}
}

void ABaddies::SetTarget(AActor* target)
{
	targetToMove = target;
}

