// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "../Prototype/CanClone.h"
#include "WarriorUnit.generated.h"

UCLASS()
class PATTERNSPROJECT_API AWarriorUnit : public APawn, public ICanClone
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AWarriorUnit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	bool bRangeUnit = false;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> Mesh;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AActor> Weapon;

	FName WeaponSocketName;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = WarriorBuilder)
	void SetFemale();

	UFUNCTION(BlueprintCallable, Category = WarriorBuilder)
	void SetMale();

	UFUNCTION(BlueprintCallable, Category = WarriorBuilder)
	void SetIsRanged(bool bNewRangeUnit);

	UFUNCTION(BlueprintCallable, Category = WarriorBuilder)
	void SetWeapon(AActor* NewWeapon);

	UFUNCTION()
	virtual UObject* Clone() override;
};
