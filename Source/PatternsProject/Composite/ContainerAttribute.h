// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAttribute.h"
#include "ContainerAttribute.generated.h"

/**
 * 
 */
UCLASS()
class PATTERNSPROJECT_API UContainerAttribute : public UBaseAttribute
{
	GENERATED_BODY()
	
private:

	TArray<UBaseAttribute*> Bonuses;

public:

	void AddBonus(UBaseAttribute* Bonus);

	void RemoveBonus(UBaseAttribute* Bonus);

	virtual void CalculateValue() override;
};
