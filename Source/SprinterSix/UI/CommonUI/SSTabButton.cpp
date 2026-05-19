// Fill out your copyright notice in the Description page of Project Settings.


#include "SSTabButton.h"

#include "CommonActionWidget.h"

void USSTabButton::UpdateUI()
{
	Super::UpdateUI();
	
	InputActionWidget->SetVisibility(ESlateVisibility::Collapsed);
}
