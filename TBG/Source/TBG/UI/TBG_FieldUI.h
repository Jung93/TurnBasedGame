// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/VerticalBox.h"
#include "TBG_FieldUI.generated.h"

/**
 * 
 */
UCLASS()
class TBG_API UTBG_FieldUI : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	//void SetBattleOrderPortrait(TArray<class ATBG_Character*> Orders);
	//void SetBattleOrderPortraitOpacity();

	//void ChangeBattleOrderPortrait();


public:
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<class UTBG_PortraitUI> PortraitUIClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UVerticalBox* VerticalBox_Portrait;
};
