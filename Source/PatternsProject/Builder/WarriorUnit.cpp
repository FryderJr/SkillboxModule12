// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorUnit.h"
#include "UObject/UObjectGlobals.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AWarriorUnit::AWarriorUnit()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
}

// Called when the game starts or when spawned
void AWarriorUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWarriorUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWarriorUnit::SetFemale()
{
	USkeletalMesh* WarriorSkeletalMesh = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("/Game/Characters/Mannequins/Meshes/SKM_Quinn_Simple.SKM_Quinn_Simple")));
	if (WarriorSkeletalMesh)
	{
		Mesh->SetSkeletalMeshAsset(WarriorSkeletalMesh);
	}
	UAnimBlueprintGeneratedClass* AnimBP = Cast<UAnimBlueprintGeneratedClass>(StaticLoadObject(UAnimBlueprintGeneratedClass::StaticClass(), NULL, TEXT("Class'/Game/Characters/Mannequins/Animations/ABP_Quinn.ABP_Quinn_C'")));
	if (AnimBP)
	{
		Mesh->SetAnimInstanceClass(AnimBP);
	}
}

void AWarriorUnit::SetMale()
{
	USkeletalMesh* WarriorSkeletalMesh = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("/Game/Characters/Mannequins/Meshes/SKM_Manny_Simple.SKM_Manny_Simple")));
	if (WarriorSkeletalMesh)
	{
		Mesh->SetSkeletalMeshAsset(WarriorSkeletalMesh);
	}
	UAnimBlueprintGeneratedClass* AnimBP = Cast<UAnimBlueprintGeneratedClass>(StaticLoadObject(UAnimBlueprintGeneratedClass::StaticClass(), NULL, TEXT("Class'/Game/Characters/Mannequins/Animations/ABP_Manny.ABP_Manny_Ñ'")));
	if (AnimBP)
	{
		Mesh->SetAnimInstanceClass(AnimBP);
	}
}

void AWarriorUnit::SetIsRanged(bool bNewRangeUnit)
{
	bRangeUnit = bNewRangeUnit;
}

void AWarriorUnit::SetWeapon(AActor* NewWeapon)
{
	if (NewWeapon)
	{
		NewWeapon->SetOwner(this);
		NewWeapon->AttachToComponent(Mesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocketName);
		Weapon = NewWeapon;
	}
}

UObject* AWarriorUnit::Clone()
{
	FActorSpawnParameters Params;
	Params.Template = this;
	AWarriorUnit* NewWarrior = GetWorld()->SpawnActor<AWarriorUnit>(this->GetClass(), Params);
	return NewWarrior;
}
