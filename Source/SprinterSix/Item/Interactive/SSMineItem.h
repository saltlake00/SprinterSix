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

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	USphereComponent* ExplosionCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
	float ExplosionDelay = 5.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
	float ExplosionRadius = 300.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
	int ExplosionDamage = 30;

protected:
	FTimerHandle ExplosionTimerHandle;
	void Explode();
	
protected:
	virtual void Activate(ASSCharacter* Character) override;

	virtual void OnPostActivated() override;
};
