// Fill out your copyright notice in the Description page of Project Settings.


#include "Anim/TBG_EnemyAnimInstance.h"
#include "TBG_Enemy.h"
#include "GameFramework/CharacterMovementComponent.h"

UTBG_EnemyAnimInstance::UTBG_EnemyAnimInstance()
{
}

void UTBG_EnemyAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	ATBG_Enemy* Enemy = Cast<ATBG_Enemy>(TryGetPawnOwner());

	if (Enemy != nullptr)
	{
		Speed = Enemy->GetVelocity().Size();
		IsAttacking = Enemy->IsAttacking();
		IsJumping = Enemy->GetCharacterMovement()->IsFalling();
	}
}

void UTBG_EnemyAnimInstance::PlayAttackMontage()
{
	if (Montage_Attack == nullptr)
		return;

	if (Montage_IsPlaying(Montage_Attack))
		return;

	Montage_Play(Montage_Attack);
}

void UTBG_EnemyAnimInstance::AnimNotify_Attack_Hit()
{
	if (AttackEvent.IsBound())
		AttackEvent.Broadcast();
}

void UTBG_EnemyAnimInstance::AnimNotify_Dead()
{
	if (DeadEvent.IsBound())
		DeadEvent.Broadcast();
}

void UTBG_EnemyAnimInstance::JumpToSection(int32 sectionIndex)
{
	FName sectionName = FName(*FString::Printf(TEXT("Section%d"), sectionIndex));

	Montage_JumpToSection(sectionName);
}
