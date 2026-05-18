// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SSHUDWidget.h"
#include "GameFramework/HUD.h"
#include "SSHUD.generated.h"

/**
 * 
 */
UCLASS()
class SPRINTERSIX_API ASSHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<USSHUDWidget> HUDWidgetClass;
	
private:
	UPROPERTY()
	TObjectPtr<USSHUDWidget> HUDWidget; 
};
