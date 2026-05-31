// Fill out your copyright notice in the Description page of Project Settings.


#include "TBG_EnemySpawnPoint.h"
#include "Components/ArrowComponent.h"

ATBG_EnemySpawnPoint::ATBG_EnemySpawnPoint()
{
	PrimaryActorTick.bCanEverTick = false;

	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	RootComponent = ArrowComponent;
	ArrowComponent->ArrowColor = FColor::Red;
	ArrowComponent->ArrowSize = 3.f;
	ArrowComponent->bIsScreenSizeScaled = true;
}
