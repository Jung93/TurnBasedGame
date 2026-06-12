// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TBG_GameModeBase.generated.h"

/**
 * 
 */


UCLASS()
class TBG_API ATBG_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ATBG_GameModeBase();

	virtual void BeginPlay() override;


private:
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<class UTBG_FieldUI> FieldUIClass;

	UPROPERTY()
	class UTBG_FieldUI* FieldUI = nullptr;


};
