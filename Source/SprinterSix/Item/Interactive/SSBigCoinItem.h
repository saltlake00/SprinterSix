// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SSCoinItem.h"
#include "SSBigCoinItem.generated.h"

UCLASS()
class SPRINTERSIX_API ASSBigCoinItem : public ASSCoinItem
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASSBigCoinItem();

	virtual void ActivateItem(AActor* Activator) override;

};
