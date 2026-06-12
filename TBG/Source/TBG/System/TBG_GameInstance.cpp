// Fill out your copyright notice in the Description page of Project Settings.


#include "TBG_GameInstance.h"

UTBG_GameInstance::UTBG_GameInstance()
{





}

void UTBG_GameInstance::SetPlayerPartyOnBattle(const TArray<TSubclassOf<class ATBG_Player>>& PlayerParty)
{
	PlayerPartyOnBattle = PlayerParty;
}


