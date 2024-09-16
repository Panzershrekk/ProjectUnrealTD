// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class PROJECTUNREALTD_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();
	void Setup(AActor* t);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float moveSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	AActor* target;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
