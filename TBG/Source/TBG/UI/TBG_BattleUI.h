// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/VerticalBox.h"
#include "Components/HorizontalBox.h"
#include "TBG_BattleUI.generated.h"

/**
 * 
 */
UCLASS()
class TBG_API UTBG_BattleUI : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;

	void SetBattleOrderPortrait(TArray<class ATBG_Character*> Orders);
	void SetBattleOrderPortraitOpacity();


public:
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<class UTBG_PortraitUI> PortraitUIClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UVerticalBox* VerticalBox_Portrait;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UHorizontalBox* BattleOrder_Portrait;

};
