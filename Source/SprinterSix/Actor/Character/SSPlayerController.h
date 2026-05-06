// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

#include "SSPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class UInputComponent;
/**
 * 
 */
UCLASS()
class SPRINTERSIX_API ASSPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;
	
protected:
	virtual void SetupInputComponent() override;
	
	void OnInputMoveTriggered(const FInputActionValue& Value);
	void OnInputLookTriggered(const FInputActionValue& Value);
	void OnInputJumpStarted();
	void OnInputSprintStarted();
	void OnInputInteractionStarted();
	
	// input mapping	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	TObjectPtr<UInputMappingContext> ThirdPersonContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	TObjectPtr<UInputAction> SprintAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	TObjectPtr<UInputAction> InteractionAction;
};
