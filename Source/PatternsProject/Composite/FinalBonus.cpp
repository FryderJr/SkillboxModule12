// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalBonus.h"
#include "ContainerAttribute.h"

void UFinalBonus::BonusExpired()
{
	auto tContainerParent = Cast<UContainerAttribute>(Parent);
	
	if (tContainerParent)
	{
		tContainerParent->RemoveBonus(this);
		Parent = nullptr;
		tContainerParent->Recalculate();
	}
}

void UFinalBonus::SetParent(UBaseAttribute* NewParent)
{
	Super::SetParent(NewParent);

	SetTime(Time);

	GetWorld()->GetTimerManager().SetTimer(FinalBonusTimer, this, &UFinalBonus::BonusExpired, Time, false);
}

void UFinalBonus::SetTime(float Value)
{
	Time = Value;
}
