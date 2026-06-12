// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TBG_FieldUI.h"
#include "UI/TBG_PortraitUI.h"
#include "TBG_Player.h"

void UTBG_FieldUI::NativeConstruct()
{
	Super::NativeConstruct();


	if (PortraitUIClass == nullptr)
		return;

	ATBG_Player* Player = Cast<ATBG_Player>(GetOwningPlayerPawn());

	if (Player == nullptr)
		return;

	const TArray<TSubclassOf<ATBG_Player>>& PlayerParty = Player->GetPlayerParty();

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
