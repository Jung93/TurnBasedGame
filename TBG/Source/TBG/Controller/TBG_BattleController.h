// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TBG_BattleController.generated.h"

/**
 * 
 */
UCLASS()
class TBG_API ATBG_BattleController : public APlayerController
{
	GENERATED_BODY()
public:



protected:

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;


	void Move(const struct FInputActionValue& Value);
	void Look(const struct FInputActionValue& Value);
	void ForTestFunction(const struct FInputActionValue& Value);



private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* BattleInputContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;



	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ForTestAction;
};
