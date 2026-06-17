// Fill out your copyright notice in the Description page of Project Settings.


#include "TBG_Player.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "TBG_AnimInstance.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Controller/TBG_PlayerController.h"
#include "System/TBG_GameModeBase.h"
#include "System/TBG_GameInstance.h"

#include "TBG_Enemy.h"
#include "Components/WidgetComponent.h"
#include "UI/TBG_BattleCommandUI.h"


// Sets default values
ATBG_Player::ATBG_Player()
{
	PrimaryActorTick.bCanEverTick = true;



	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;



	CameraArm = CreateDefaultSubobject<USpringArmComponent>("CameraArm");
	CameraArm->SetupAttachment(RootComponent);
	CameraArm->TargetArmLength = 400.0f;
	CameraArm->bUsePawnControlRotation = true;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	PlayerCamera->SetupAttachment(CameraArm, USpringArmComponent::SocketName); 
	PlayerCamera->bUsePawnControlRotation = false; 

	BattleCommandUI = CreateDefaultSubobject<UWidgetComponent>(TEXT("CommandUI"));
	BattleCommandUI->SetupAttachment(GetMesh());
	BattleCommandUI->SetWidgetSpace(EWidgetSpace::Screen);


}

void ATBG_Player::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	AnimInstance = Cast<UTBG_AnimInstance>(GetMesh()->GetAnimInstance());

}

void ATBG_Player::BeginPlay()
{
	Super::BeginPlay();

	AnimInstance->OnMontageEnded.AddDynamic(this, &ThisClass::AttackEnd);
	AnimInstance->AttackEvent.AddUObject(this, &ThisClass::Attack_Hit);
	AnimInstance->FieldAttackEvent.AddUObject(this, &ThisClass::FieldAttack_Hit);
}

// Called every frame
void ATBG_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATBG_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	//{
	//	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
	//	{
	//		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	//	}
	//}

	//if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	//{
	//	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
	//	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &Super::Jump);
	//	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);
	//	EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &ThisClass::Attack);

	//}


}

void ATBG_Player::Move(const FInputActionValue& Value)
{
	FVector2d MovementVector = Value.Get<FVector2d>();

	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ATBG_Player::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ATBG_Player::Attack(const FInputActionValue& Value)
{
	if (IsAttack)
		return;

	GetWorld()->GetTimerManager().ClearTimer(AttackTimer);

	bool isPress = Value.Get<bool>();

	if (isPress)
	{
		IsAttack = true;

		AnimInstance->PlayAttackMontage();
		AnimInstance->JumpToSection(CurAttackSection);

		CurAttackSection = (CurAttackSection) % 3 + 1;


		GetWorld()->GetTimerManager().SetTimer(
			AttackTimer,
			this,
			&ATBG_Player::ResetCombo,
			1.0f,
			false
		);

	}

}

void ATBG_Player::FieldAttack(const FInputActionValue& Value)
{
	if (IsAttack)
		return;

	bool isPress = Value.Get<bool>();

	if (isPress)
	{
		IsAttack = true;

		AnimInstance->PlayFieldAttackMontage();

	}
}

void ATBG_Player::AttackEnd(class UAnimMontage* Montage, bool bInterrupted)
{
	IsAttack = false;

	if (bPendingEndTurn)
	{
		bPendingEndTurn = false;
		BattleAttackTarget = nullptr;
		EndTurn();
	}
}

void ATBG_Player::ResetCombo()
{
	CurAttackSection = 1;
}

void ATBG_Player::SetBattleCamera(TSubclassOf<UTBG_BattleCommandUI> BattleCommandUIClass)
{
	CameraArm->bUsePawnControlRotation = false;
	CameraArm->TargetArmLength = 450.f;
	CameraArm->SetRelativeRotation(FRotator(12.f, -20.f, 0.f));
	CameraArm->SetRelativeLocation(FVector(0.f, 90.f, 0.f));
	CameraArm->TargetOffset = FVector(0.f, 0.f, 60.f);
	CameraArm->SocketOffset = FVector::ZeroVector;


	BattleCommandUI->SetRelativeLocationAndRotation(FVector(0.0f, -200.0f, 200.0f), FRotator::ZeroRotator);
	BattleCommandUI->SetWidgetClass(BattleCommandUIClass);
	BattleCommandUI->SetCastShadow(false);

}

void ATBG_Player::HideBattleCommandUI()
{
	BattleCommandUI->SetWidgetClass(nullptr);
}

void ATBG_Player::ShowBattleCommandUIWidget(TSubclassOf<UTBG_BattleCommandUI> Class)
{
	BattleCommandUI->SetWidgetClass(Class);
}

void ATBG_Player::ExecuteBattleAttack(ATBG_Enemy* Target)
{
	BattleAttackTarget = Target;
	bPendingEndTurn = true;
	IsAttack = true;
	AnimInstance->PlayAttackMontage();
	AnimInstance->JumpToSection(1);
}

void ATBG_Player::FieldAttack_Hit()
{
	FHitResult hitResult;
	FCollisionQueryParams params(NAME_None, false, this);

	FVector forward = GetActorForwardVector();
	FQuat quat = FQuat::FindBetweenVectors(FVector(0, 0, 1), forward);

	float attackRadius = 100.0f;

	FVector Center = GetActorLocation() + forward * AttackRange * 0.5f;
	FVector Start = GetActorLocation() + forward * AttackRange * 0.5f;
	FVector End = GetActorLocation() + forward * AttackRange * 0.5f;

	//FVector Start = GetActorLocation() + FVector(0, 0, attackRadius);
	//FVector End = GetActorLocation() + FVector(0, 0, attackRadius) + forward * AttackRange;
	//FVector Center = (Start + End) * 0.5f;

	bool bResult = GetWorld()->SweepSingleByChannel(
		OUT hitResult,
		Start,
		End,
		quat,
		ECC_GameTraceChannel2,//TBG_FieldAttack
		FCollisionShape::MakeCapsule(attackRadius, AttackRange * 0.5f),
		params
	);

	FColor drawColor = FColor::Green;

	ATBG_Enemy* HitEnemy = Cast<ATBG_Enemy>(hitResult.GetActor());

	if (bResult && HitEnemy->IsValidLowLevel())
	{
		drawColor = FColor::Red;

		UTBG_GameInstance* GM = Cast<UTBG_GameInstance>(GetGameInstance());

		GM->SetEnemyOnBattle(HitEnemy->GetClass());
		GM->SetPlayerPartyOnBattle(PlayerParty);

		FName LevelName = BattleLevelName.ToSoftObjectPath().GetAssetFName();
		UGameplayStatics::OpenLevel(this, LevelName);
	}


	DrawDebugCapsule(
		GetWorld(),
		Center,
		AttackRange * 0.5f,
		attackRadius,
		quat,
		drawColor,
		false,
		3.0f
	);

}

void ATBG_Player::Attack_Hit()
{
	FHitResult hitResult;
	FCollisionQueryParams params(NAME_None, false, this);

	FVector forward = GetActorForwardVector();
	FQuat quat = FQuat::FindBetweenVectors(FVector(0, 0, 1), forward);


	float attackRadius = 100.0f;

	FVector Center = GetActorLocation() + forward * AttackRange * 0.5f;
	FVector Start = GetActorLocation() + forward * AttackRange * 0.5f;
	FVector End = GetActorLocation() + forward * AttackRange * 0.5f;

	bool bResult = GetWorld()->SweepSingleByChannel(
		OUT hitResult,
		Start,
		End,
		quat,
		ECC_GameTraceChannel1,
		FCollisionShape::MakeCapsule(attackRadius, AttackRange * 0.5f),
		params
	);

	FColor drawColor = FColor::Green;

	if (bResult && hitResult.GetActor()->IsValidLowLevel())
	{
		drawColor = FColor::Red;

	}

	DrawDebugCapsule(
		GetWorld(),
		Center,
		AttackRange * 0.5f,
		attackRadius,
		quat,
		drawColor,
		false,
		3.0f
	);

}