// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnitPathController.generated.h"

UCLASS()
class PATTERNSPROJECT_API AUnitPathController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUnitPathController();

	UFUNCTION()
	void SetTarget(FVector NewTargetLocation);

	UFUNCTION()
	void SetUnits(TArray<ACharacter*> Units);

	UFUNCTION()
	void StartMovement();

protected:

	TArray<ACharacter*> SpawnedUnits;

	FVector TargetLocation;

	FVector NextNavPathPoint;

	FTimerHandle FTimeToRefreshPath;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void RefreshPath();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
