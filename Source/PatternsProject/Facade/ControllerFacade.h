// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ControllerFacade.generated.h"

/**
 *  ������� �����. ����� ���������� ����� ��� ������� ���������� �������� � ����� ������ � MOBA-����. 
 *  UnitSpawnController ������ ��� �������� ������. UnitPathController �������� �� �� ���������
 */
UCLASS()
class PATTERNSPROJECT_API UControllerFacade : public UObject
{
	GENERATED_BODY()

	UControllerFacade();

public:

	void StartWave();

protected:

	class UUnitSpawnController* SpawnController;
	class AUnitPathController* PathController;

	UFUNCTION()
	void Spawned(TArray<ACharacter*> SpawnedUnits);
};
