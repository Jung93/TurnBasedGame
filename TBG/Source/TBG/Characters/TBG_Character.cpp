// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TBG_Character.h"

// Sets default values
ATBG_Character::ATBG_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATBG_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATBG_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATBG_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

