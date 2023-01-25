// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardianBuilder.h"
#include "Spear.h"

AActor* UGuardianBuilder::GetResult()
{
	return Guardian;
}

IBuilderInterface* UGuardianBuilder::CreateUnit()
{
	Guardian = Cast<AWarriorUnit>(GetWorld()->SpawnActor(AWarriorUnit::StaticClass()));
	if (Guardian)
	{
		Guardian->SetFemale();
	}
	return this;
}

IBuilderInterface* UGuardianBuilder::CreateWeapon()
{
	ASpear* Spear = Cast<ASpear>(GetWorld()->SpawnActor(ASpear::StaticClass()));
	if (Guardian)
	{
		Guardian->SetWeapon(Spear);
	}
	return this;
}
