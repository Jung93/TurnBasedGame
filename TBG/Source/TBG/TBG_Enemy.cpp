// Fill out your copyright notice in the Description page of Project Settings.


#include "TBG_Enemy.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ATBG_Enemy::ATBG_Enemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// 타겟 선택용 카메라 — 기본값은 BP 에디터에서 맵에 맞게 조정 필요
	TargetingCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TargetingCamera"));
	TargetingCamera->SetupAttachment(RootComponent);
	TargetingCamera->SetRelativeLocation(FVector(-350.f, 150.f, 200.f));
	TargetingCamera->SetRelativeRotation(FRotator(20.f, 0.f, 0.f));
}

// Called when the game starts or when spawned
void ATBG_Enemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATBG_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATBG_Enemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

