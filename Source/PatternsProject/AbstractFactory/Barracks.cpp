// Fill out your copyright notice in the Description page of Project Settings.


#include "Barracks.h"
#include "Soldier.h"

APawn* AMilitiaBarracks::TrainSoldier()
{
	auto Soldier = Cast<AMilitiaSoldier>(GetWorld()->SpawnActor(AMilitiaSoldier::StaticClass()));
	return Soldier;
}

APawn* AMilitiaBarracks::TrainEliteSoldier()
{
	auto Soldier = Cast<AEliteMilitiaSoldier>(GetWorld()->SpawnActor(AEliteMilitiaSoldier::StaticClass()));
	return Soldier;
}

APawn* ACrownBarracks::TrainSoldier()
{
	auto Soldier = Cast<ACrownSoldier>(GetWorld()->SpawnActor(ACrownSoldier::StaticClass()));
	return Soldier;
}

APawn* ACrownBarracks::TrainEliteSoldier()
{
	auto Soldier = Cast<AEliteCrownSoldier>(GetWorld()->SpawnActor(AEliteCrownSoldier::StaticClass()));
	return Soldier;
}
