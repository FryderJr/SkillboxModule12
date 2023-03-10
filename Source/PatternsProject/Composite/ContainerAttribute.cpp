// Fill out your copyright notice in the Description page of Project Settings.


#include "ContainerAttribute.h"

void UContainerAttribute::AddBonus(UBaseAttribute* Bonus)
{
	Bonuses.Add(Bonus);
	Bonus->SetParent(this);
}

void UContainerAttribute::RemoveBonus(UBaseAttribute* Bonus)
{
	Bonuses.Remove(Bonus);
	Bonus->SetParent(nullptr);
}

void UContainerAttribute::CalculateValue()
{
	Super::CalculateValue();

	float tFinalValue = 0.0f;
	for (int32 i = 0; i < Bonuses.Num(); i++)
	{
		Bonuses[i]->CalculateValue();
		tFinalValue += Bonuses[i]->GetFinalValue();
	}
	FinalValue += tFinalValue;
}
