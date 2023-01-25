// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuilderInterface.h"
#include "WarriorUnit.h"
#include "UObject/NoExportTypes.h"
#include "WarriorBuilder.generated.h"

/**
 * 
 */
UCLASS()
class PATTERNSPROJECT_API UWarriorBuilder : public UObject, public IBuilderInterface
{
	GENERATED_BODY()
	
private:

	UPROPERTY(meta = (AllowPrivateAccess = "true"), BlueprintReadOnly, VisibleAnywhere, Category = Warrior)
	AWarriorUnit* Warrior{ nullptr };

public:

	virtual AActor* GetResult() override;

	virtual IBuilderInterface* CreateUnit() override;

	virtual IBuilderInterface* CreateWeapon() override;
};
