// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuilderInterface.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UnitGeneratorDirector.generated.h"

/**
 * 
 */
UCLASS()
class PATTERNSPROJECT_API UUnitGeneratorDirector : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	static void GenerateUnit(IBuilderInterface* Generator);
};
