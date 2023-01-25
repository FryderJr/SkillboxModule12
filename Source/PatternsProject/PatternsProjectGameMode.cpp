// Copyright Epic Games, Inc. All Rights Reserved.

#include "PatternsProjectGameMode.h"
#include "PatternsProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

APatternsProjectGameMode::APatternsProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
