// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAttribute.h"

void UBaseAttribute::SetBaseValue(float Value)
{
	BaseValue = Value;
}

float UBaseAttribute::GetBaseValue()
{
	return BaseValue;
}

void UBaseAttribute::SetBaseMultiplier(float Value)
{
	BaseMultiplier = Value;
}

float UBaseAttribute::GetBaseMultiplier()
{
	return BaseMultiplier;
}

void UBaseAttribute::SetParent(UBaseAttribute* NewParent)
{
	Parent = NewParent;
}

void UBaseAttribute::CalculateValue()
{
	FinalValue = BaseValue * (1 + BaseMultiplier);
}

void UBaseAttribute::Recalculate()
{
	if (Parent)
	{
		Parent->Recalculate();
	}
	else
	{
		CalculateValue();
	}
}

float UBaseAttribute::GetFinalValue()
{
	return FinalValue;
}
