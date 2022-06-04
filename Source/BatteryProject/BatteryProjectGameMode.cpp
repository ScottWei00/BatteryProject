// Copyright Epic Games, Inc. All Rights Reserved.

#include "BatteryProjectGameMode.h"
#include "BatteryProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABatteryProjectGameMode::ABatteryProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
