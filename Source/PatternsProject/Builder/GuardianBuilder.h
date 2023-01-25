// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuilderInterface.h"
#include "WarriorUnit.h"
#include "UObject/NoExportTypes.h"
#include "GuardianBuilder.generated.h"

/**
 * 
 */
UCLASS()
class PATTERNSPROJECT_API UGuardianBuilder : public UObject, public IBuilderInterface
{
	GENERATED_BODY()
	
private:

	UPROPERTY(meta = (AllowPrivateAccess = "true"), BlueprintReadOnly, VisibleAnywhere, Category = Warrior)
	AWarriorUnit* Guardian { nullptr };

public:

	virtual AActor* GetResult() override;

	virtual IBuilderInterface* CreateUnit() override;

	virtual IBuilderInterface* CreateWeapon() override;
};
