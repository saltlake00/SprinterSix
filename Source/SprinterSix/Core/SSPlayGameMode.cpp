// Fill out your copyright notice in the Description page of Project Settings.


#include "SSPlayGameMode.h"

#include "SSGameState.h"
#include "Actor/Character/SSCharacter.h"
#include "Actor/Character/SSPlayerController.h"
#include "UI/SSHUD.h"

ASSPlayGameMode::ASSPlayGameMode()
{
	PlayerControllerClass = ASSPlayerController::StaticClass();
	DefaultPawnClass = ASSCharacter::StaticClass();
	GameStateClass = ASSGameState::StaticClass();
	HUDClass = ASSHUD::StaticClass();	
}
