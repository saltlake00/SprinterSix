// Fill out your copyright notice in the Description page of Project Settings.


#include "SSBigCoinItem.h"


// Sets default values
ASSBigCoinItem::ASSBigCoinItem()
{
	//CoinItem 상속받은 멤버변수 초기화
	PointValue = 50;
	//BaseItem 상속받은 멤버변수 초기화
	ItemType = "BigCoin";
}

void ASSBigCoinItem::ActivateItem(AActor* Activator)
{
	//인터페이스 상속 함수
	Super::ActivateItem(Activator);
	
	//인터페이스에서 Destroy(); 호출하는 함수 상속받아서 사용
	DestroyItem();
}

