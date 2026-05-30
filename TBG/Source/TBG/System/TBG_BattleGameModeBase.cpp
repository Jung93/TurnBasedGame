// Fill out your copyright notice in the Description page of Project Settings.


#include "TBG_BattleGameModeBase.h"
#include "System/TBG_GameInstance.h"
#include "TBG_Enemy.h"
#include "TBG_Player.h"


ATBG_BattleGameModeBase::ATBG_BattleGameModeBase()
{


}

void ATBG_BattleGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    UTBG_GameInstance* gm = Cast<UTBG_GameInstance>(GetGameInstance());

    TSubclassOf<ATBG_Enemy> EnemyOnBattle = gm->GetEnemy();
    TArray<TSubclassOf<ATBG_Player>> PlayerPartyOnBattle = gm->GetPlayerParty();

    if (EnemyOnBattle == nullptr && PlayerPartyOnBattle.IsEmpty())
        return;

    const ATBG_Enemy* FieldEnemy = GetDefault<ATBG_Enemy>(EnemyOnBattle);
    TArray<TSubclassOf<ATBG_Enemy>> EnemyInfos = FieldEnemy->GetEnemyInfos();

    float Spacing = 400.f;
    float TotalWidth = Spacing * (EnemyInfos.Num() - 1);

    for (int32 i = 0; i < EnemyInfos.Num(); i++)
    {
        if (EnemyInfos[i])
        {
            FVector EnemySpawnLocation(0.f, -TotalWidth * 0.5f + Spacing * i, 192.f);
            ATBG_Enemy* SpawnedEnemy = GetWorld()->SpawnActor<ATBG_Enemy>(EnemyInfos[i], FTransform(EnemySpawnLocation));
            SpawnedEnemy->SpawnDefaultController();


            //BattleOrder에 SpawnedEnemy 삽입


        }
    }

    TotalWidth = Spacing * (PlayerPartyOnBattle.Num() - 1);

    for (int32 i = 0; i < PlayerPartyOnBattle.Num(); i++)
    {
        if (PlayerPartyOnBattle[i])
        {
            FVector PartySpawnLocation(620.f, -TotalWidth * 0.5f + Spacing * i, 192.f);
            FRotator PartySpawnRotation(0.f, 180.f, 0.f);

            ATBG_Player* SpawnedParty = GetWorld()->SpawnActor<ATBG_Player>(PlayerPartyOnBattle[i], FTransform(PartySpawnRotation, PartySpawnLocation));
            SpawnedParty->SpawnDefaultController();




        }


    }




}


