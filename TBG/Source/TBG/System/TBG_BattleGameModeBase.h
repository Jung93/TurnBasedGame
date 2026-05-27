// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TBG_BattleGameModeBase.generated.h"

/**
 * 
 */


UCLASS()
class TBG_API ATBG_BattleGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ATBG_BattleGameModeBase();


private:

	UPROPERTY()
	TArray<ACharacter*> FirstMove;


	UPROPERTY()
	TArray<ACharacter*> BattleOrder;


	int32 CurrentOrder = 0;


};
