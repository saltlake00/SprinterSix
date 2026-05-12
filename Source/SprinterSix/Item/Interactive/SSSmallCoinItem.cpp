// Fill out your copyright notice in the Description page of Project Settings.


#include "SSSmallCoinItem.h"


// Sets default values
ASSSmallCoinItem::ASSSmallCoinItem()
{
	PointValue = 10;
	ItemType = "SmallCoin";
}

void ASSSmallCoinItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);
	
	DestroyItem();
}



