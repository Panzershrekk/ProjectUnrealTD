// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "../IAttackType.h"
#include "Bullet.h"
#include "Tower.generated.h"

UCLASS()
class PROJECTUNREALTD_API ATower : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATower();
	void ProcessAttack();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float range;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float fireRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TSubclassOf<AActor> AttackType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TSubclassOf<ABullet> Bullet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TArray<USceneComponent*> BulletStartPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USphereComponent* RangeSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShopConfig")
	float price;


	UFUNCTION()
	void GetBaddiesInRange(TArray<ABaddies*>& OutBaddies);

	UFUNCTION()
	void OnEnemyEnterRange(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnEnemyExitRange(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	AActor* AttackTypeSpawned;
	IIAttackType* IAttackType;
	float TimeSinceLastAttack = 0.0f;
	bool isBaddiesInRange = false;
	bool canAttack = false;
	TArray<ABaddies*> BaddiesInRange;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
