// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/TBG_BattleController.h"
#include "TBG_Player.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "System/TBG_GameInstance.h"
#include "TBG_Enemy.h"
#include "Kismet/GameplayStatics.h"


void ATBG_BattleController::BeginPlay()
{
	Super::BeginPlay();

    
    UTBG_GameInstance* gm = Cast<UTBG_GameInstance>(GetGameInstance());

    TSubclassOf<ATBG_Enemy> EnemyOnBattle = gm->GetEnemy();

    if (EnemyOnBattle == nullptr)
        return;




}

void ATBG_BattleController::SetupInputComponent()
{
	Super::SetupInputComponent();

    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(BattleInputContext, 0);
    }

    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent)) {

        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);

    }

}

void ATBG_BattleController::Move(const FInputActionValue& Value)
{
}

void ATBG_BattleController::Look(const FInputActionValue& Value)
{
	ATBG_Player* player = Cast<ATBG_Player>(GetPawn());

	if (player)
		player->Look(Value);
}
