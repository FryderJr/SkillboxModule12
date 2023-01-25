// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BuilderInterface.generated.h"

// паттерн строитель. Здесь реализован интерфейс строителя. Его конкретная реализация находится в GuardianBuilder, а директор в классе UnitGeneratorDirector
// В данном случае строитель реализует логику поэтапного создания юнита. Сначала выбирается тип юнита, затем создаётся его оружие. В конечном итоге возвращается готовый юнит

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBuilderInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PATTERNSPROJECT_API IBuilderInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual AActor* GetResult() PURE_VIRTUAL(IBuilderInterface::GetResult, return nullptr;);

	virtual IBuilderInterface* CreateUnit() PURE_VIRTUAL(IBuilderInterface::CreateUnit, return nullptr;);

	virtual IBuilderInterface* CreateWeapon() PURE_VIRTUAL(IBuilderInterface::CreateWeapon, return nullptr;);
};
