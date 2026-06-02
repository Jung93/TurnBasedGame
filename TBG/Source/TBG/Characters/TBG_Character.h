// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TBG_Character.generated.h"



USTRUCT(BlueprintType)
struct FStatus
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	int32 Level = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	int32 HP = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	int32 MP = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	int32 Agility = 0;

	bool operator>(const FStatus& Other) const
	{
		return Agility > Other.Agility;
	};

};

UCLASS()
class TBG_API ATBG_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATBG_Character();


	virtual void BeginPlay() override;


	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	TSoftObjectPtr<UTexture2D> GetPortraitImage() { return Portrait; }



	bool operator>(const ATBG_Character& Other) const
	{
		return Status.Agility > Other.Status.Agility;
	};



public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	FStatus Status;

	UPROPERTY(EditAnywhere, Category = "Portrait")
	TSoftObjectPtr<UTexture2D> Portrait = nullptr;





};
