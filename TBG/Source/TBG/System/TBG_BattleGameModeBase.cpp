// Fill out your copyright notice in the Description page of Project Settings.


#include "TBG_BattleGameModeBase.h"
#include "System/TBG_GameInstance.h"
#include "System/TBG_EnemySpawnPoint.h"
#include "System/TBG_PlayerPartySpawnPoint.h"
#include "Characters/TBG_Character.h"
#include "TBG_Enemy.h"
#include "TBG_Player.h"
#include "EngineUtils.h"
#include "Controller/TBG_BattleController.h"
#include "UI/TBG_BattleUI.h"

ATBG_BattleGameModeBase::ATBG_BattleGameModeBase()
{


}

void ATBG_BattleGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    UTBG_GameInstance* Gm = Cast<UTBG_GameInstance>(GetGameInstance());

    TSubclassOf<ATBG_Enemy> EnemyOnBattle = Gm->GetEnemy();
    TArray<TSubclassOf<ATBG_Player>> PlayerPartyOnBattle = Gm->GetPlayerParty();

    if (EnemyOnBattle == nullptr || PlayerPartyOnBattle.IsEmpty())
        return;

    const ATBG_Enemy* FieldEnemy = GetDefault<ATBG_Enemy>(EnemyOnBattle);
    TArray<TSubclassOf<ATBG_Enemy>> EnemyInfos = FieldEnemy->GetEnemyInfos();

    ATBG_EnemySpawnPoint* EnemySpawnPoint = nullptr;
    for (ATBG_EnemySpawnPoint* Actor : TActorRange<ATBG_EnemySpawnPoint>(GetWorld()))
    {
        EnemySpawnPoint = Actor;
        break;
    }

    if (EnemySpawnPoint && EnemyInfos.Num() > 0)
    {
        const FVector Center = EnemySpawnPoint->GetActorLocation();
        const FVector Right = EnemySpawnPoint->GetActorRightVector();
        const FRotator SpawnRotation = EnemySpawnPoint->GetActorRotation();
        const float Spacing = EnemySpawnPoint->Spacing;
        const float TotalWidth = Spacing * (EnemyInfos.Num() - 1);

        for (int32 i = 0; i < EnemyInfos.Num(); i++)
        {
            if (EnemyInfos[i])
            {
                FVector EnemySpawnLocation = Center + Right * (-TotalWidth * 0.5f + Spacing * i);
                ATBG_Enemy* SpawnedEnemy = GetWorld()->SpawnActor<ATBG_Enemy>(EnemyInfos[i], FTransform(SpawnRotation, EnemySpawnLocation));
                SpawnedEnemy->SpawnDefaultController();

                //BattleOrder에 SpawnedEnemy 삽입
                BattleOrder.Add(SpawnedEnemy);


            }
        }
    }

    ATBG_PlayerPartySpawnPoint* PlayerPartySpawnPoint = nullptr;
    for (ATBG_PlayerPartySpawnPoint* Actor : TActorRange<ATBG_PlayerPartySpawnPoint>(GetWorld()))
    {
        PlayerPartySpawnPoint = Actor;
        break;
    }

    if (PlayerPartySpawnPoint && PlayerPartyOnBattle.Num() > 0)
    {
        const FVector Center = PlayerPartySpawnPoint->GetActorLocation();
        const FVector Right = PlayerPartySpawnPoint->GetActorRightVector();
        const FRotator SpawnRotation = PlayerPartySpawnPoint->GetActorRotation();
        const float Spacing = PlayerPartySpawnPoint->Spacing;
        const float TotalWidth = Spacing * (PlayerPartyOnBattle.Num() - 1);

        for (int32 i = 0; i < PlayerPartyOnBattle.Num(); i++)
        {
            if (PlayerPartyOnBattle[i])
            {
                FVector PlayerPartySpawnLocation = Center + Right * (-TotalWidth * 0.5f + Spacing * i);
                ATBG_Player* SpawnedParty = GetWorld()->SpawnActor<ATBG_Player>(PlayerPartyOnBattle[i], FTransform(SpawnRotation, PlayerPartySpawnLocation));
                SpawnedParty->SpawnDefaultController();


                //BattleOrder에 SpawnedParty 삽입
                BattleOrder.Add(SpawnedParty);


            }
        }
    }

    //float PlayerSpacing = 400.f;
    //float PlayerTotalWidth = PlayerSpacing * (PlayerPartyOnBattle.Num() - 1);

    //for (int32 i = 0; i < PlayerPartyOnBattle.Num(); i++)
    //{
    //    if (PlayerPartyOnBattle[i])
    //    {
    //        FVector PartySpawnLocation(620.f, -PlayerTotalWidth * 0.5f + PlayerSpacing * i, 192.f);
    //        FRotator PartySpawnRotation(0.f, 180.f, 0.f);

    //        ATBG_Player* SpawnedParty = GetWorld()->SpawnActor<ATBG_Player>(PlayerPartyOnBattle[i], FTransform(PartySpawnRotation, PartySpawnLocation));
    //        SpawnedParty->SpawnDefaultController();
    //    }
    //}


        //임시 컨트롤러 빙의. 나중에는 BattleOrder에서 첫번째 캐릭터에 빙의. 또는 FirstMove의 첫  캐릭터

    
        BattleOrder.Sort([](const ATBG_Character& a, const ATBG_Character& b)
            {
                if (a.Agility > b.Agility)
                    return true;
                return false;
            });

        ATBG_BattleController* BC = Cast<ATBG_BattleController>(GetWorld()->GetFirstPlayerController());
        BC->Possess(BattleOrder[2]);

    if (BattleUIClass)
    {
        BattleUI = CreateWidget<UTBG_BattleUI>(GetWorld()->GetFirstPlayerController(), BattleUIClass);
        if (BattleUI)
            BattleUI->AddToViewport();
    }
}


