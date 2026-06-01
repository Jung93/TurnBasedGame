// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TBG_PlayerPartySpawnPoint.generated.h"

UCLASS()
class TBG_API ATBG_PlayerPartySpawnPoint : public AActor
{
	GENERATED_BODY()
	
public:
	ATBG_PlayerPartySpawnPoint();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	float Spacing = 400.f;

private:
	UPROPERTY(VisibleAnywhere)
	class UArrowComponent* ArrowComponent;


};
