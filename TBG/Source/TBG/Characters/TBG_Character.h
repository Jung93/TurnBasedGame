// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TBG_Character.generated.h"

UCLASS()
class TBG_API ATBG_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATBG_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	TSoftObjectPtr<UTexture2D> GetPortraitImage() { return Portrait; }


	UPROPERTY(EditAnywhere, Category = "Status")
	int32 Agility = 0;

	UPROPERTY(EditAnywhere, Category = "Portrait")
	TSoftObjectPtr<UTexture2D> Portrait = nullptr;

};
