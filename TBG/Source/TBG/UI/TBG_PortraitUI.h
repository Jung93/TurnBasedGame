// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "TBG_PortraitUI.generated.h"

/**
 * 
 */
UCLASS()
class TBG_API UTBG_PortraitUI : public UUserWidget
{
	GENERATED_BODY()
	

public:
	void SetHPText(int32 Value);
	void SetMPText(int32 Value);


public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UImage* Portrait;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UProgressBar* ProgressBar_HP;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* ProgressBar_HPText;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UProgressBar* ProgressBar_MP;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* ProgressBar_MPText;
};
