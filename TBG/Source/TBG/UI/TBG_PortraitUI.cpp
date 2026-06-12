// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TBG_PortraitUI.h"

void UTBG_PortraitUI::SetHPText(int32 Value)
{

	FString HPStr = FString::FromInt(Value);
	FText HP = FText::FromString(HPStr);

	ProgressBar_HPText->SetText(HP);
}

void UTBG_PortraitUI::SetMPText(int32 Value)
{
	FString MPStr = FString::FromInt(Value);
	FText MP = FText::FromString(MPStr);

	ProgressBar_MPText->SetText(MP);
}
