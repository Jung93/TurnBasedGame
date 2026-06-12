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

	virtual void BeginPlay() override;


	TArray<class ATBG_Character*> GetFirstMove() { return FirstMove; };

	UFUNCTION(BlueprintCallable)
	TArray<class ATBG_Character*> GetBattleOrder() { return BattleOrder; };


	void AdvancedTurn();

private:

	UPROPERTY()
	TArray<class ATBG_Character*> FirstMove;


	UPROPERTY(VisibleAnywhere)
	TArray<class ATBG_Character*> BattleOrder;



	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<class UTBG_BattleUI> BattleUIClass;

	UPROPERTY()
	class UTBG_BattleUI* BattleUI = nullptr;
};
