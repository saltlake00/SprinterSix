// Fill out your copyright notice in the Description page of Project Settings.


#include "SSCharacterAnimInstance.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void USSCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	PlayerCharacter = Cast<ACharacter>(GetOwningActor());

	if (PlayerCharacter == nullptr)
	{
		return;
	}
	
	CharacterMovement = PlayerCharacter->GetCharacterMovement();
}

void USSCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (PlayerCharacter == nullptr)
	{
		return;
	}

	CharacterVelocity = CharacterMovement->Velocity;
	GroundSpeed = CharacterVelocity.Size2D();

	FRotator CharacterRotation = PlayerCharacter->GetActorRotation();
	float RotationValue = CalculateDirection(CharacterVelocity, CharacterRotation);

	if (CharacterMovement->bOrientRotationToMovement)
	{
		Direction = FMath::Clamp(RotationValue, -45, 45);
	}
	else
	{
		Direction = RotationValue;
	}

	bool bMoving = FMath::IsNearlyZero(GroundSpeed) == false;
	bool bAccelerating = CharacterMovement->GetCurrentAcceleration().IsNearlyZero() == false;

	if (bMoving && bAccelerating)
	{
		bShouldMove = true;
	}

	bIsFalling = CharacterMovement->IsFalling();
}
