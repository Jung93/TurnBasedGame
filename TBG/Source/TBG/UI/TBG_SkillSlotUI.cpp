// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/TBG_SkillSlotUI.h"
#include "Components/TextBlock.h"

void UTBG_SkillSlotUI::SetSkillInfo(const FSkillInfo& Info)
{
	if (Text_SkillName)
		Text_SkillName->SetText(Info.SkillName);

	if (Text_MPCost)
		Text_MPCost->SetText(FText::Format(INVTEXT("MP {0}"), Info.MPCost));
}

void UTBG_SkillSlotUI::SetSelected(bool bSelected)
{
	FLinearColor Color = bSelected ? FLinearColor(1.f, 0.8f, 0.f, 1.f) : FLinearColor::White;

	if (Text_SkillName)
		Text_SkillName->SetColorAndOpacity(Color);

	if (Text_MPCost)
		Text_MPCost->SetColorAndOpacity(Color);
}
