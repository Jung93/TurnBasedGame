// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/TBG_SkillCommandUI.h"
#include "UI/TBG_SkillSlotUI.h"
#include "Components/VerticalBox.h"

void UTBG_SkillCommandUI::InitSkills(const TArray<FSkillInfo>& InSkills)
{
	VerticalBox_Skills->ClearChildren();
	SkillSlots.Empty();

	for (const FSkillInfo& Skill : InSkills)
	{
		UTBG_SkillSlotUI* SkillSlot = CreateWidget<UTBG_SkillSlotUI>(GetOwningPlayer(), SkillSlotClass);
		if (!SkillSlot) continue;

		SkillSlot->SetSkillInfo(Skill);
		SkillSlot->SetSelected(false);
		VerticalBox_Skills->AddChild(SkillSlot);
		SkillSlots.Add(SkillSlot);
	}

	if (!SkillSlots.IsEmpty())
		SkillSlots[0]->SetSelected(true);
}

void UTBG_SkillCommandUI::SetSelectedIndex(int32 Index)
{
	for (int32 i = 0; i < SkillSlots.Num(); i++)
		SkillSlots[i]->SetSelected(i == Index);
}
