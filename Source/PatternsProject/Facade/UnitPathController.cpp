// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitPathController.h"
#include "NavigationSystem.h"
#include "NavigationPath.h"
#include "AIController.h"
#include "GameFramework/Character.h"

// Sets default values
AUnitPathController::AUnitPathController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AUnitPathController::SetTarget(FVector NewTargetLocation)
{
	TargetLocation = NewTargetLocation;
}

void AUnitPathController::SetUnits(TArray<ACharacter*> Units)
{
	SpawnedUnits = Units;
}

void AUnitPathController::StartMovement()
{
	RefreshPath();
}

// Called when the game starts or when spawned
void AUnitPathController::BeginPlay()
{
	Super::BeginPlay();
	
}

void AUnitPathController::RefreshPath()
{
	UNavigationPath* NavPath = UNavigationSystemV1::FindPathToLocationSynchronously(this, SpawnedUnits[0]->GetActorLocation(), TargetLocation, SpawnedUnits[0]);
	if (NavPath)
	{
		if (NavPath->GetPathLength() > 1)
		{
			NextNavPathPoint = NavPath->PathPoints[1];
		}
	}
	for (int32 i = 0; i < SpawnedUnits.Num(); i++)
	{
		AAIController* Controller = Cast<AAIController>(SpawnedUnits[i]->Controller);
		Controller->MoveToLocation(NextNavPathPoint, 25.0f, true, false);
	}
	if ((NextNavPathPoint - TargetLocation).Length() > 50.0f)
	{
		GetWorldTimerManager().SetTimer(FTimeToRefreshPath, this, &AUnitPathController::RefreshPath, 5.0f, false);
	}
}

// Called every frame
void AUnitPathController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

