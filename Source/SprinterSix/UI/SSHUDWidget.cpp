// Fill out your copyright notice in the Description page of Project Settings.


#include "SSHUDWidget.h"

#include "Core/SSGameState.h"

void USSHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	ASSGameState* GameState = GetWorld()->GetGameState<ASSGameState>();
	if (GameState == nullptr)
	{
		return;
	}
	
}
