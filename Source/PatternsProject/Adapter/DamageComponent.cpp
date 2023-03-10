// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageComponent.h"

// Sets default values for this component's properties
UDamageComponent::UDamageComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UDamageComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UDamageComponent::Multiply()
{
	FActorSpawnParameters Params;
	Params.Template = GetOwner();
	
	auto NewWarrior = GetWorld()->SpawnActor<AActor>(GetOwner()->GetClass(), Params);
}

void UDamageComponent::Destory()
{
	GetOwner()->Destroy();
}

