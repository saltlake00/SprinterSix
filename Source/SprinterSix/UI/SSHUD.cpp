// Fill out your copyright notice in the Description page of Project Settings.


#include "SSHUD.h"

void ASSHUD::BeginPlay()
{
	Super::BeginPlay();

	if (HUDWidgetClass == nullptr)
	{
		return;
	}

	HUDWidget = CreateWidget<USSHUDWidget>(GetOwningPlayerController(), HUDWidgetClass);
	if (HUDWidget == nullptr)
	{
		return;
	}

	HUDWidget->AddToViewport();
}
