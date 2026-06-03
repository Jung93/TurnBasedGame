// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TBG_BattleUI.h"
#include "UI/TBG_PortraitUI.h"
#include "TBG_Player.h"
#include "Characters/TBG_Character.h"
#include "System/TBG_GameInstance.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"

void UTBG_BattleUI::NativeConstruct()
{
	Super::NativeConstruct();

	if (PortraitUIClass == nullptr) 
		return;

	UTBG_GameInstance* GM = Cast<UTBG_GameInstance>(GetWorld()->GetGameInstance());

	if (GM == nullptr)
		return;

	TArray<TSubclassOf<ATBG_Player>> PlayerParty = GM->GetPlayerParty();

	for (const TSubclassOf<ATBG_Player>& PlayerClass : PlayerParty)
	{
		if (PlayerClass == nullptr) 
			continue;

		UTBG_PortraitUI* PortraitUI = CreateWidget<UTBG_PortraitUI>(GetOwningPlayer(), PortraitUIClass);

		if (PortraitUI == nullptr) 
			continue;

		ATBG_Player* Party = PlayerClass->GetDefaultObject<ATBG_Player>();
		TSoftObjectPtr<UTexture2D> PortraitImage = Party->GetPortraitImage();

		if (!PortraitImage.IsNull() && PortraitUI->Portrait)
		{
			UTexture2D* Texture = PortraitImage.LoadSynchronous();

			if (Texture)
			{
				PortraitUI->Portrait->SetBrushFromTexture(Texture);

			}
		}

		if (VerticalBox_Portrait)
			VerticalBox_Portrait->AddChild(PortraitUI);
	}
}

void UTBG_BattleUI::SetBattleOrderPortrait(TArray<ATBG_Character*> Orders)
{
	if (Orders.IsEmpty())
		return;



	for (ATBG_Character* Character : Orders)
	{
		UTexture2D* Texture = Character->GetPortraitImage().LoadSynchronous();

		if (Texture)
		{


			USizeBox* SB = NewObject<USizeBox>(this);
			SB->SetWidthOverride(128.f);
			SB->SetHeightOverride(128.f);
			UImage* PortraitImage = NewObject<UImage>(this);
			PortraitImage->SetBrushFromTexture(Texture);
			SB->AddChild(PortraitImage);
			BattleOrder_Portrait->AddChild(SB);
		}

	}


}

