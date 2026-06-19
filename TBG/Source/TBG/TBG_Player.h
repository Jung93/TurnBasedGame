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
	ATBG_Player();

protected:
	virtual void PostInitializeComponents()override;

	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

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

	// 커맨드 UI 위젯만 다시 표시
	void ShowBattleCommandUIWidget(TSubclassOf<UTBG_BattleCommandUI> Class);

	// 전투용 공격 실행 → 애니메이션 종료 후 EndTurn 호출
	void ExecuteBattleAttack(class ATBG_Enemy* Target);


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

	UPROPERTY()
	class ATBG_Enemy* BattleAttackTarget = nullptr;

	bool bPendingEndTurn = false;


	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "UI", meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent* BattleCommandUI;

};
