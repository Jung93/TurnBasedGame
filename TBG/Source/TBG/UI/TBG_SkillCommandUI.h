// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Characters/TBG_Character.h"
#include "TBG_SkillCommandUI.generated.h"

UCLASS()
class TBG_API UTBG_SkillCommandUI : public UUserWidget
{
	GENERATED_BODY()

public:
	void InitSkills(const TArray<FSkillInfo>& InSkills);
	void SetSelectedIndex(int32 Index);
	int32 GetSkillCount() const { return SkillSlots.Num(); }

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<class UTBG_SkillSlotUI> SkillSlotClass;

private:
	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* VerticalBox_Skills;

	UPROPERTY()
	TArray<class UTBG_SkillSlotUI*> SkillSlots;
};
