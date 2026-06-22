// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Characters/TBG_Character.h"
#include "TBG_SkillSlotUI.generated.h"

UCLASS()
class TBG_API UTBG_SkillSlotUI : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetSkillInfo(const FSkillInfo& Info);
	void SetSelected(bool bSelected);

private:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Text_SkillName;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Text_MPCost;
};
