// Fill out your copyright notice in the Description page of Project Settings.


#include "TBG_GameModeBase.h"
#include "System/TBG_GameInstance.h"

#include "Characters/TBG_Character.h"
#include "TBG_Enemy.h"
#include "TBG_Player.h"
#include "UI/TBG_FieldUI.h"

ATBG_GameModeBase::ATBG_GameModeBase()
{



}

void ATBG_GameModeBase::BeginPlay()
{
	Super::BeginPlay();



    if (FieldUIClass)
    {
        FieldUI = CreateWidget<UTBG_FieldUI>(GetWorld()->GetFirstPlayerController(), FieldUIClass);
        if (FieldUI)
        {
            FieldUI->AddToViewport();

        }

    }

}

