// Fill out your copyright notice in the Description page of Project Settings.


#include "SSPlayerController.h"

void ASSPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ASSPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	//TODO: ULocalPlayer 알아보기
	
	//향상된입력 로컬플레이어 서브시스템을 가져온다. 
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	//서브시스템으로 매핑컨텍스트를 추가해줌
	Subsystem->AddMappingContext(ThirdPersonContext, 0);
}

void ASSPlayerController::OnUnPossess()
{
	Super::OnUnPossess();
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	Subsystem->RemoveMappingContext(ThirdPersonContext);
}

void ASSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComp = Cast<UEnhancedInputComponent>(InputComponent);
	if (EnhancedInputComp == nullptr)
	{
		return;
	}
	
	EnhancedInputComp->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::OnInputMoveTriggered);
	EnhancedInputComp->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::OnInputLookTriggered);
	EnhancedInputComp->BindAction(JumpAction, ETriggerEvent::Started,this, &ThisClass::OnInputJumpStarted);
	EnhancedInputComp->BindAction(SprintAction, ETriggerEvent::Started, this, &ThisClass::OnInputSprintStarted);
	EnhancedInputComp->BindAction(InteractionAction, ETriggerEvent::Started, this, &ThisClass::OnInputInteractionStarted);
	
}

void ASSPlayerController::OnInputMoveTriggered(const FInputActionValue& Value)
{
	UE_LOG(LogTemp,Warning,TEXT("Input Move"))
}

void ASSPlayerController::OnInputLookTriggered()
{
	UE_LOG(LogTemp, Warning, TEXT("Input Look"))
	
}

void ASSPlayerController::OnInputJumpStarted()
{
	UE_LOG(LogTemp, Warning, TEXT("Input Jump"))
	
}

void ASSPlayerController::OnInputSprintStarted()
{
	UE_LOG(LogTemp, Warning, TEXT("Input Sprint"))
}


void ASSPlayerController::OnInputInteractionStarted()
{
	UE_LOG(LogTemp, Warning, TEXT("Input Interaction"))
}
