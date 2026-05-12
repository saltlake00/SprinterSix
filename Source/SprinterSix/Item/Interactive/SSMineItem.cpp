// Fill out your copyright notice in the Description page of Project Settings.


#include "SSMineItem.h"


// Sets default values
ASSMineItem::ASSMineItem()
{
	// 멤버변수 초기화
	ExplosionDelay = 5.0f;
	ExplosionRadius = 300.0f;
	ExplosionDamage = 30.0f;
	// BaseItem 상속 멤버변수 초기화
	ItemType = "Mine";
}

void ASSMineItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);

	DestroyItem();
}
