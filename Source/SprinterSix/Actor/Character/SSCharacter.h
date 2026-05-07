// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SSCharacter.generated.h"

UCLASS()
class SPRINTERSIX_API ASSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASSCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	void SetSprint(bool bActive);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Sprint)
	float SprintSpeed = 1000;

	UPROPERTY()
	float NormalSpeed;
};
