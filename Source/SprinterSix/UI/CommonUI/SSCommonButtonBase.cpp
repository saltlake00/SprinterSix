// Fill out your copyright notice in the Description page of Project Settings.


#include "SSCommonButtonBase.h"

void USSCommonButtonBase::NativePreConstruct()
{
	UpdateUI();
}

void USSCommonButtonBase::NativeConstruct()
{
	Super::NativeConstruct();
	
	UpdateUI();
}

void USSCommonButtonBase::UpdateUI()
{
	ButtonText->SetText(Text);
}


