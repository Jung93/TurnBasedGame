// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TBG_BattleController.generated.h"

UENUM()
enum class EBattleCommandState : uint8
{
	Idle,           // 입력 대기 없음 (애니메이션 재생 중)
	CommandSelect,  // 커맨드 선택 대기 중
	EnemySelect,    // 적 타겟 선택 중 (Attack 커맨드 선택 후)
};

UCLASS()
class TBG_API ATBG_BattleController : public APlayerController
{
	GENERATED_BODY()
public:

	void ShowBattleCommandUI(class ATBG_Player* CurPlayer);

	void EnterCommandSelect();
	void EnterEnemySelect();
	void ExitEnemySelect();

protected:

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn* InPawn) override;


	void Move(const struct FInputActionValue& Value);
	void ForTestFunction(const struct FInputActionValue& Value);

	void OnAttackCommand(const struct FInputActionValue& Value);
	void OnSkillCommand(const struct FInputActionValue& Value);
	void OnSelectNextTarget(const struct FInputActionValue& Value);
	void OnSelectPrevTarget(const struct FInputActionValue& Value);
	void OnConfirm(const struct FInputActionValue& Value);
	void OnCancel(const struct FInputActionValue& Value);

	void FocusOnEnemy(class ATBG_Enemy* Enemy);


private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* BattleInputContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ForTestAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* AttackCommandAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* SkillCommandAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* SelectNextTargetAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* SelectPrevTargetAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ConfirmAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* CancelAction;

	EBattleCommandState CommandState = EBattleCommandState::Idle;

	UPROPERTY()
	TArray<class ATBG_Enemy*> EnemyTargets;

	int32 CurrentTargetIndex = 0;

public:
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<class UTBG_BattleCommandUI> BattleCommandUIClass;

	UPROPERTY()
	class UTBG_BattleCommandUI* BattleCommandUI = nullptr;
};
