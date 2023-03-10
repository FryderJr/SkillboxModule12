// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAttribute.h"
#include "FinalBonus.generated.h"

/**
 * 
 */
UCLASS()
class PATTERNSPROJECT_API UFinalBonus : public UBaseAttribute
{
	GENERATED_BODY()
	
private:

	float Time = 15.0f;

	FTimerHandle FinalBonusTimer;

	UFUNCTION()
	void BonusExpired();

public:

	virtual void SetParent(UBaseAttribute* NewParent) override;

	void SetTime(float Value);
};
