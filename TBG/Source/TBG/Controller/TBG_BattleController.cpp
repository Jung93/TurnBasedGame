// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/TBG_BattleController.h"
#include "TBG_Player.h"
#include "TBG_Enemy.h"
#include "Characters/TBG_Character.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "System/TBG_GameInstance.h"
#include "System/TBG_BattleGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "UI/TBG_BattleCommandUI.h"

void ATBG_BattleController::BeginPlay()
{
	Super::BeginPlay();

	BattleCommandUI = CreateWidget<UTBG_BattleCommandUI>(GetWorld()->GetFirstPlayerController(), BattleCommandUIClass);
}

void ATBG_BattleController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(BattleInputContext, 0);
	}

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(ForTestAction, ETriggerEvent::Started, this, &ThisClass::ForTestFunction);
		EnhancedInputComponent->BindAction(AttackCommandAction, ETriggerEvent::Started, this, &ThisClass::OnAttackCommand);
		EnhancedInputComponent->BindAction(SkillCommandAction, ETriggerEvent::Started, this, &ThisClass::OnSkillCommand);
		EnhancedInputComponent->BindAction(SelectNextTargetAction, ETriggerEvent::Started, this, &ThisClass::OnSelectNextTarget);
		EnhancedInputComponent->BindAction(SelectPrevTargetAction, ETriggerEvent::Started, this, &ThisClass::OnSelectPrevTarget);
		EnhancedInputComponent->BindAction(ConfirmAction, ETriggerEvent::Started, this, &ThisClass::OnConfirm);
		EnhancedInputComponent->BindAction(CancelAction,  ETriggerEvent::Started, this, &ThisClass::OnCancel);
	}
}

void ATBG_BattleController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (ATBG_Player* CurPlayer = Cast<ATBG_Player>(InPawn))
	{
		CurPlayer->SetBattleCamera(BattleCommandUIClass);
		CommandState = EBattleCommandState::CommandSelect;
		EnemyTargets.Empty();
		CurrentTargetIndex = 0;
	}
}

void ATBG_BattleController::Move(const FInputActionValue& Value)
{
}

// 테스트용 턴 스킵 (CommandSelect 상태에서만 동작)
void ATBG_BattleController::ForTestFunction(const FInputActionValue& Value)
{
	if (CommandState != EBattleCommandState::CommandSelect) 
		return;

	ATBG_Player* CurPlayer = Cast<ATBG_Player>(GetPawn());
	if (!CurPlayer) 
		return;

	CurPlayer->HideBattleCommandUI();
	CommandState = EBattleCommandState::Idle;
	CurPlayer->EndTurn();
}

void ATBG_BattleController::OnAttackCommand(const FInputActionValue& Value)
{
	if (CommandState != EBattleCommandState::CommandSelect) 
		return;

	EnterEnemySelect();
}

void ATBG_BattleController::OnSkillCommand(const FInputActionValue& Value)
{
	if (CommandState != EBattleCommandState::CommandSelect) 
		return;
	// 스킬 선택 UI 표시
}

void ATBG_BattleController::OnSelectNextTarget(const FInputActionValue& Value)
{
	if (CommandState != EBattleCommandState::EnemySelect || EnemyTargets.IsEmpty()) 
		return;

	CurrentTargetIndex = (CurrentTargetIndex + 1) % EnemyTargets.Num();
	FocusOnEnemy(EnemyTargets[CurrentTargetIndex]);
}

void ATBG_BattleController::OnSelectPrevTarget(const FInputActionValue& Value)
{
	if (CommandState != EBattleCommandState::EnemySelect || EnemyTargets.IsEmpty()) 
		return;

	CurrentTargetIndex = (CurrentTargetIndex - 1 + EnemyTargets.Num()) % EnemyTargets.Num();
	FocusOnEnemy(EnemyTargets[CurrentTargetIndex]);
}

void ATBG_BattleController::OnConfirm(const FInputActionValue& Value)
{
	if (CommandState != EBattleCommandState::EnemySelect) 
		return;

	if (!EnemyTargets.IsValidIndex(CurrentTargetIndex)) 
		return;

	ATBG_Enemy* Target = EnemyTargets[CurrentTargetIndex];
	ATBG_Player* CurPlayer = Cast<ATBG_Player>(GetPawn());
	if (!CurPlayer || !Target) 
		return;

	// 플레이어 카메라로 복귀 후 공격 실행
	SetViewTargetWithBlend(CurPlayer, 0.3f);
	CommandState = EBattleCommandState::Idle;
	EnemyTargets.Empty();

	// 공격 애니메이션 재생 → AttackEnd에서 자동으로 EndTurn 호출됨
	CurPlayer->ExecuteBattleAttack(Target);
}

void ATBG_BattleController::OnCancel(const FInputActionValue& Value)
{
	if (CommandState != EBattleCommandState::EnemySelect) 
		return;

	ExitEnemySelect();
}

void ATBG_BattleController::FocusOnEnemy(ATBG_Enemy* Enemy)
{
	if (!Enemy) 
		return;

	SetViewTargetWithBlend(Enemy, 0.3f);
}

void ATBG_BattleController::EnterCommandSelect()
{
	CommandState = EBattleCommandState::CommandSelect;
	EnemyTargets.Empty();
	CurrentTargetIndex = 0;

	if (ATBG_Player* CurPlayer = Cast<ATBG_Player>(GetPawn()))
	{
		CurPlayer->ShowBattleCommandUIWidget(BattleCommandUIClass);
		SetViewTargetWithBlend(CurPlayer, 0.3f);
	}
}

void ATBG_BattleController::EnterEnemySelect()
{
	EnemyTargets.Empty();

	ATBG_BattleGameModeBase* GM = Cast<ATBG_BattleGameModeBase>(GetWorld()->GetAuthGameMode());
	if (!GM) 
		return;

	// BattleOrder는 Agility 내림차순 정렬 → 필터링하면 빠른 적이 앞에 옴
	for (ATBG_Character* Char : GM->GetBattleOrder())
	{
		if (ATBG_Enemy* Enemy = Cast<ATBG_Enemy>(Char))
		{
			EnemyTargets.Add(Enemy);
		}
	}

	if (EnemyTargets.IsEmpty()) 
		return;

	if (ATBG_Player* CurPlayer = Cast<ATBG_Player>(GetPawn()))
	{
		CurPlayer->HideBattleCommandUI();
	}

	CommandState = EBattleCommandState::EnemySelect;
	CurrentTargetIndex = 0;
	FocusOnEnemy(EnemyTargets[0]);
}

void ATBG_BattleController::ExitEnemySelect()
{
	EnemyTargets.Empty();
	CurrentTargetIndex = 0;
	CommandState = EBattleCommandState::CommandSelect;

	ATBG_Player* CurPlayer = Cast<ATBG_Player>(GetPawn());
	if (!CurPlayer) 
		return;

	CurPlayer->ShowBattleCommandUIWidget(BattleCommandUIClass);
	SetViewTargetWithBlend(CurPlayer, 0.3f);
}

void ATBG_BattleController::ShowBattleCommandUI(ATBG_Player* CurPlayer)
{
	FVector2D ScreenPos;

	if (ProjectWorldLocationToScreen(CurPlayer->GetActorLocation(), ScreenPos))
	{
		ScreenPos.X += 100.f;
		BattleCommandUI->SetLocation(ScreenPos);
		BattleCommandUI->SetVisibility(ESlateVisibility::Visible);
	}
}
