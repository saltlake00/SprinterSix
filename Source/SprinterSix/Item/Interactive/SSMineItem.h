// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/SSBaseItem.h"
#include "SSMineItem.generated.h"

UCLASS()
class SPRINTERSIX_API ASSMineItem : public ASSBaseItem
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASSMineItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
	float ExplosionDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
	float ExplosionRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
	float ExplosionDamage;
	
	virtual void ActivateItem(AActor* Activator) override;
	
	
};
