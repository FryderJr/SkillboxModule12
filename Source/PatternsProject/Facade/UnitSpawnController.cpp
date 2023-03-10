// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitSpawnController.h"
#include "TimerManager.h"

UUnitSpawnController::UUnitSpawnController()
{

}

void UUnitSpawnController::StartSpawn()
{
	GetWorld()->GetTimerManager().SetTimer(FTimeToSpawn, this, &UUnitSpawnController::Spawn, TimeToSpawn, false);
}

void UUnitSpawnController::Spawn()
{
	if (UnitCount <= 0)
	{
		Spawned.Broadcast(SpawnedUnits);
		return;
	}

	auto Soldier = Cast<ACharacter>(GetWorld()->SpawnActor(UnitType));
	SpawnedUnits.Add(Soldier);
	UnitCount--;
	GetWorld()->GetTimerManager().SetTimer(FTimeToSpawn, this, &UUnitSpawnController::Spawn, TimeToSpawn, false);
}
