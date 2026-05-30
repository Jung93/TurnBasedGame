// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/TBG_BattleController.h"
#include "TBG_Player.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "System/TBG_GameInstance.h"
#include "TBG_Enemy.h"
#include "Kismet/GameplayStatics.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"


void ATBG_BattleController::BeginPlay()
{
	Super::BeginPlay();

    
    UTBG_GameInstance* gm = Cast<UTBG_GameInstance>(GetGameInstance());

    TSubclassOf<ATBG_Enemy> EnemyOnBattle = gm->GetEnemy();

    if (EnemyOnBattle == nullptr)
        return;

    const ATBG_Enemy* EnemyCDO = GetDefault<ATBG_Enemy>(EnemyOnBattle);
    TArray<TSubclassOf<ATBG_Enemy>> EnemyInfos = EnemyCDO->GetEnemyInfos();

    float Spacing = 400.f;
    float TotalWidth = Spacing * (EnemyInfos.Num() - 1);

    for (int32 i = 0; i < EnemyInfos.Num(); i++)
    {
        if (EnemyInfos[i])
        {
            FVector EnemySpawnLocation(0.f, -TotalWidth * 0.5f + Spacing * i, 192.f);
            ATBG_Enemy* SpawnedEnemy = GetWorld()->SpawnActor<ATBG_Enemy>(EnemyInfos[i], FTransform(EnemySpawnLocation));
            SpawnedEnemy->SpawnDefaultController();
        }
    }

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
