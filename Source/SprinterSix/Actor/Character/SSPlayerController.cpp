// Fill out your copyright notice in the Description page of Project Settings.


#include "SSPlayerController.h"

#include "GameFramework/Character.h"

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
	UE_LOG(LogTemp,Warning,TEXT("Input Move"));
	
	//입력값 2D벡터 수신
	FVector2D MovementVector = Value.Get<FVector2D>();
	UE_LOG(LogTemp, Warning, TEXT("%s"),*MovementVector.ToString());
	
	//컨트롤러 회전값 수신
	const FRotator Rotation = GetControlRotation();
	//회전값 중 Z회전(Yaw)만 남김
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	
	//전방 방향
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
	//우측 방향 (x축)
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	GetCharacter()->AddMovementInput(ForwardDirection, MovementVector.X);
	GetCharacter()->AddMovementInput(RightDirection, MovementVector.Y);
	
	
}

void ASSPlayerController::OnInputLookTriggered(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Input Look"))
	
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	
	UE_LOG(LogTemp, Warning, TEXT("%s"),*LookAxisVector.ToString());
	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
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
