// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/TBG_Character.h"
#include "UI/TBG_BattleCommandUI.h"
#include "TBG_Player.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;


UCLASS()
class TBG_API ATBG_Player : public ATBG_Character
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATBG_Player();

protected:
	virtual void PostInitializeComponents()override;

	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Attack(const FInputActionValue& Value);
	void FieldAttack(const FInputActionValue& Value);

	UFUNCTION()
	void AttackEnd(class UAnimMontage* Montage, bool bInterrupted);

	bool IsAttacking() { return IsAttack; }


	void ResetCombo();
	struct FTimerHandle AttackTimer;


	void FieldAttack_Hit();
	void Attack_Hit();

	const TArray<TSubclassOf<ATBG_Player>>& GetPlayerParty() const { return PlayerParty; }

	void SetBattleCamera(TSubclassOf<UTBG_BattleCommandUI> BattleCommandUIClass);

	void HideBattleCommandUI();


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* PlayerCamera;

private:
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	//UInputMappingContext* DefaultMappingContext;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	//UInputAction* JumpAction;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	//UInputAction* MoveAction;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	//UInputAction* LookAction;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	//UInputAction* AttackAction;

private:
	UPROPERTY()
	class UTBG_AnimInstance* AnimInstance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation", meta = (AllowPrivateAccess = "true"))
	bool IsAttack = false;

	int32 CurAttackSection = 1;

	float AttackRange = 300.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Battle", meta = (AllowPrivateAccess = "true"))
	TSoftObjectPtr<UWorld> BattleLevelName;


	UPROPERTY(EditAnywhere, Category = "Party", meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<ATBG_Player>> PlayerParty;


	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "UI", meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent* BattleCommandUI;

};
