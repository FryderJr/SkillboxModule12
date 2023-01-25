// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorBuilder.h"
#include "Sword.h"

AActor* UWarriorBuilder::GetResult()
{
	return Warrior;
}

IBuilderInterface* UWarriorBuilder::CreateUnit()
{
	Warrior = Cast<AWarriorUnit>(GetWorld()->SpawnActor(AWarriorUnit::StaticClass()));
	if (Warrior)
	{
		Warrior->SetMale();
	}
	return this;
}

IBuilderInterface* UWarriorBuilder::CreateWeapon()
{
	ASword* Sword = Cast<ASword>(GetWorld()->SpawnActor(ASword::StaticClass()));
	if (Warrior)
	{
		Warrior->SetWeapon(Sword);
	}
	return this;
}
