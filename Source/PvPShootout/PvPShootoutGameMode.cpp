// Copyright Epic Games, Inc. All Rights Reserved.

#include "PvPShootoutGameMode.h"
#include "PvPShootoutCharacter.h"
#include "UObject/ConstructorHelpers.h"

APvPShootoutGameMode::APvPShootoutGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	// static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/PvPShootout/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	// DefaultPawnClass = PlayerPawnClassFinder.Class;
}
