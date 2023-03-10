// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageHandler.h"
#include "DestructionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PATTERNSPROJECT_API UDestructionComponentAdapter : public UActorComponent, public IDamageHandler
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDestructionComponentAdapter();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	class UDamageComponent* DamageComponent;

public:	

	virtual void DealDamage(DamageInfo Info) override;
};
