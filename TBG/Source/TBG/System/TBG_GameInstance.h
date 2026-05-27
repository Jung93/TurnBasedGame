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


	void SetEnemyOnBattle(TSubclassOf<class ATBG_Enemy> EnemyClass) { EnemyOnBattle = EnemyClass; }

	TSubclassOf<class ATBG_Enemy> GetEnemy() { return EnemyOnBattle; }


protected:
	UPROPERTY(VisibleAnywhere)
	TSubclassOf<class ATBG_Enemy> EnemyOnBattle = nullptr;

};
