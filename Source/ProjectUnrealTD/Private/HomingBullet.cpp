// Fill out your copyright notice in the Description page of Project Settings.


#include "HomingBullet.h"
#include "../Baddies.h"
// Sets default values
AHomingBullet::AHomingBullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Super::ABullet();

}

// Called when the game starts or when spawned
void AHomingBullet::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AHomingBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (target)
	{
		FVector TargetLocation = target->GetActorLocation();
		FVector Direction = (TargetLocation - GetActorLocation()).GetSafeNormal();
		FVector NewLocation = GetActorLocation() + Direction * moveSpeed * DeltaTime;

		SetActorLocation(NewLocation);
		if (FVector::Dist(NewLocation, TargetLocation) <= 10)
		{
			ABaddies* baddie = Cast<ABaddies>(target);
			if (baddie)
			{
				baddie->ChangeLife(damage);
			}
			Destroy();
		}
	}
}

