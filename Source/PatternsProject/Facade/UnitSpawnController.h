// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Character.h"
#include "UnitSpawnController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnitsSpawnedSignature, TArray<ACharacter*>, SpawnedUnits);
/**
 * 
 */
UCLASS()
class PATTERNSPROJECT_API UUnitSpawnController : public UObject
{
	GENERATED_BODY()

	UUnitSpawnController();

public:
	int32 UnitCount;

	float TimeToSpawn;

	FVector SpawnPoint;

	TSubclassOf<ACharacter> UnitType;

	TArray<ACharacter*> SpawnedUnits;

	UFUNCTION()
	void StartSpawn();

	UPROPERTY(BlueprintAssignable, Category = Events)
	FOnUnitsSpawnedSignature Spawned;

protected:

	FTimerHandle FTimeToSpawn;

	UFUNCTION()
	void Spawn();
};
