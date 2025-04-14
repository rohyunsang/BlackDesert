// Copyright Epic Games, Inc. All Rights Reserved.

#include "BlackDesertGameMode.h"
#include "BlackDesertCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABlackDesertGameMode::ABlackDesertGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
