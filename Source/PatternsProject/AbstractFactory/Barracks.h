// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Barracks.generated.h"

// ������� ����������� �������. ����� ABarracks ������������ ����� ��������� ����������� �������. � ������ ������ ��� ����� ��� ���������� ����
// ����� ������: ������� ������ � ������� ������
// ���������� ���������� ����������� ������� 2 - ��� ����� ��������� AMilitiaBaracks � ����������� ����� ACrownBarracks
// � ������ �������� ���������� ������� ���������, �� ������ - ����������� �����

UCLASS()
class PATTERNSPROJECT_API ABarracks : public AActor
{
	GENERATED_BODY()
	
public:	
	
	virtual APawn* TrainSoldier() PURE_VIRTUAL(ABarracks::TrainSoldier, return nullptr;);

	virtual APawn* TrainEliteSoldier() PURE_VIRTUAL(ABarracks::TrainEliteSoldier, return nullptr;);

};

UCLASS()
class PATTERNSPROJECT_API AMilitiaBarracks : public ABarracks
{
	GENERATED_BODY()

public:

	virtual APawn* TrainSoldier() override;

	virtual APawn* TrainEliteSoldier() override;
};

UCLASS()
class PATTERNSPROJECT_API ACrownBarracks : public ABarracks
{
	GENERATED_BODY()

public:

	virtual APawn* TrainSoldier() override;

	virtual APawn* TrainEliteSoldier() override;
};