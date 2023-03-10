// Fill out your copyright notice in the Description page of Project Settings.


#include "DestructionComponent.h"
#include "DamageComponent.h"

// Sets default values for this component's properties
UDestructionComponentAdapter::UDestructionComponentAdapter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UDestructionComponentAdapter::BeginPlay()
{
	Super::BeginPlay();

	DamageComponent = GetOwner()->FindComponentByClass<UDamageComponent>();
	
}

void UDestructionComponentAdapter::DealDamage(DamageInfo Info)
{
	if (Info.Type == DamageType::Energy)
	{
		DamageComponent->Multiply();
	}

	if (Info.Type == DamageType::Explosion)
	{
		DamageComponent->Destory();
	}
}

