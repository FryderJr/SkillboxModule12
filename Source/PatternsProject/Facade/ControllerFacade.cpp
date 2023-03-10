// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerFacade.h"
#include "UnitSpawnController.h"
#include "UnitPathController.h"


UControllerFacade::UControllerFacade()
{

}

void UControllerFacade::StartWave()
{
	if (!SpawnController)
	{
		SpawnController = NewObject<UUnitSpawnController>();
		SpawnController->Spawned.AddDynamic(this, &UControllerFacade::Spawned);
	}
	SpawnController->StartSpawn();
}

void UControllerFacade::Spawned(TArray<ACharacter*> SpawnedUnits)
{
	if (!PathController)
	{
		PathController = NewObject<AUnitPathController>();
	}
	PathController->SetUnits(SpawnedUnits);
	PathController->SetTarget(FVector(0, 1, 2));
	PathController->StartMovement();
}

