// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/SSBaseItem.h"
#include "SSCoinItem.generated.h"

class ASSCharacter;

UCLASS()
class SPRINTERSIX_API ASSCoinItem : public ASSBaseItem
{
	GENERATED_BODY()

public:
	ASSCoinItem();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Item")
	int32 PointValue = 10;
	
protected:
	virtual void Activate(ASSCharacter* Character) override;
};
