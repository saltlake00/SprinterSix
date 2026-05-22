// Fill out your copyright notice in the Description page of Project Settings.


#include "SSStackStubWidget.h"

TOptional<FUIInputConfig> USSStackStubWidget::GetDesiredInputConfig() const
{
	FUIInputConfig UIConfig(ECommonInputMode::Menu,
	                        EMouseCaptureMode::NoCapture,
	                        EMouseLockMode::DoNotLock, 
	                        false);
	UIConfig.bIgnoreMoveInput = false;
	UIConfig.bIgnoreLookInput = false;
	return UIConfig;
}

// 호출자가 toptional로 받은 이유
// t옵셔널이 안되면 기본값을 쓰려고?
