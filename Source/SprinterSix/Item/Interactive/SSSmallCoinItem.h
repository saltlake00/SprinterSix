// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SSCoinItem.h"
#include "SSSmallCoinItem.generated.h"

UCLASS()
class SPRINTERSIX_API ASSSmallCoinItem : public ASSCoinItem
{
	GENERATED_BODY()

public:
	ASSSmallCoinItem();

	virtual void ActivateItem(AActor* Activator) override;
};
