// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SSCommonButtonBase.h"
#include "SSTabButton.generated.h"

/**
 * 
 */
UCLASS()
class SPRINTERSIX_API USSTabButton : public USSCommonButtonBase
{
	GENERATED_BODY()
	
public:
	virtual void UpdateUI() override;
};
