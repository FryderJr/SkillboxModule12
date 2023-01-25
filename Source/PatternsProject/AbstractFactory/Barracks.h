// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Barracks.generated.h"

// паттерн абстрактная фабрика. Класс ABarracks представляет собой интерфейс абстрактной фабрики. В данном случае это барак для тренировки двух
// типов юнитов: обычных солдат и элитных воинов
// конкретных реализаций абстрактной фабрики 2 - это барак ополчения AMilitiaBaracks и королевский барак ACrownBarracks
// в первом проходят тренировку солдаты ополчения, во втором - королевские бойцы

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