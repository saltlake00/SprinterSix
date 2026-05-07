// Fill out your copyright notice in the Description page of Project Settings.


#include "SSCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"


ASSCharacter::ASSCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASSCharacter::BeginPlay()
{
	Super::BeginPlay();

	NormalSpeed = GetCharacterMovement()->MaxWalkSpeed;
}

void ASSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASSCharacter::SetSprint(bool bActive)
{
	if (bActive)
	{
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
	}
}
