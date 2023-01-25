// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitGeneratorDirector.h"

void UUnitGeneratorDirector::GenerateUnit(IBuilderInterface* Generator)
{
	if (Generator)
	{
		Generator->CreateUnit()->CreateWeapon();
	}
}
