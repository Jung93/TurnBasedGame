// Fill out your copyright notice in the Description page of Project Settings.


#include "TBG_PlayerController.h"
#include "TBG/TBG_Player.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "TBG_BattleGameModeBase.h"

void ATBG_PlayerController::BeginPlay()
{
	Super::BeginPlay();



}

void ATBG_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(FieldInputContext, 0);
    }

    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent)) {

        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ThisClass::Jump);
        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);
        EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &ThisClass::Attack);

    }

}


void ATBG_PlayerController::Move(const FInputActionValue& Value)
{
    ATBG_Player* player = Cast<ATBG_Player>(GetPawn());

    if (player)
        player->Move(Value);



}

void ATBG_PlayerController::Look(const FInputActionValue& Value)
{
    ATBG_Player* player = Cast<ATBG_Player>(GetPawn());

    if (player)
        player->Look(Value);
}

void ATBG_PlayerController::Jump()
{
    ATBG_Player* player = Cast<ATBG_Player>(GetPawn());

    if (player)
        player->Jump();
}

void ATBG_PlayerController::Attack(const FInputActionValue& Value)
{
    ATBG_Player* player = Cast<ATBG_Player>(GetPawn());

    if (player)
        player->FieldAttack(Value);
}

void ATBG_PlayerController::FieldAttack(const FInputActionValue& Value)
{
    ATBG_Player* player = Cast<ATBG_Player>(GetPawn());

    if (player)
        player->FieldAttack(Value);
}
