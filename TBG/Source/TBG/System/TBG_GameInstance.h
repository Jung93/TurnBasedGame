// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TBG_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TBG_API UTBG_GameInstance : public UGameInstance
{
	GENERATED_BODY()
	

public:
	UTBG_GameInstance();

	//플레이어 파티
	void SetPlayerPartyOnBattle(TSubclassOf<class ATBG_Player> Player, TArray<TSubclassOf<class ATBG_Player>> PlayerParty);

	//필드 적
	void SetEnemyOnBattle(TSubclassOf<class ATBG_Enemy> EnemyClass) { EnemyOnBattle = EnemyClass; }

	TArray<TSubclassOf<class ATBG_Player>> GetPlayerParty() { return PlayerPartyOnBattle; };
	TSubclassOf<class ATBG_Enemy> GetEnemy() { return EnemyOnBattle; }


protected:
	UPROPERTY(VisibleAnywhere)
	TArray<TSubclassOf<class ATBG_Player>> PlayerPartyOnBattle;

	UPROPERTY(VisibleAnywhere)
	TSubclassOf<class ATBG_Enemy> EnemyOnBattle = nullptr;


};
