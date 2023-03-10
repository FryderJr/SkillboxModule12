// Fill out your copyright notice in the Description page of Project Settings.


#include "Soldier.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ASoldier::ASoldier()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
}

// Called when the game starts or when spawned
void ASoldier::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASoldier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

AEliteSoldier::AEliteSoldier()
{
	GetCapsuleComponent()->InitCapsuleSize(64.f, 128.0f);
}

AMilitiaSoldier::AMilitiaSoldier()
{
}

void AMilitiaSoldier::Attack()
{
}

AEliteMilitiaSoldier::AEliteMilitiaSoldier()
{
}

void AEliteMilitiaSoldier::Attack()
{
}

void AEliteMilitiaSoldier::SpecialAttack()
{
}

ACrownSoldier::ACrownSoldier()
{
}

void ACrownSoldier::Attack()
{
}

AEliteCrownSoldier::AEliteCrownSoldier()
{
}

void AEliteCrownSoldier::Attack()
{
}

void AEliteCrownSoldier::SpecialAttack()
{
}
