// Fill out your copyright notice in the Description page of Project Settings.


#include "System/TBG_PlayerPartySpawnPoint.h"
#include "Components/ArrowComponent.h"


// Sets default values
ATBG_PlayerPartySpawnPoint::ATBG_PlayerPartySpawnPoint()
{
	PrimaryActorTick.bCanEverTick = false;

	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	RootComponent = ArrowComponent;
	ArrowComponent->ArrowColor = FColor::Red;
	ArrowComponent->ArrowSize = 3.f;
	ArrowComponent->bIsScreenSizeScaled = true;
}

