// Fill out your copyright notice in the Description page of Project Settings.


#include "TBG_AnimInstance.h"
#include "TBG_Player.h"
#include "GameFramework/CharacterMovementComponent.h"

UTBG_AnimInstance::UTBG_AnimInstance()
{
}

void UTBG_AnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	auto pawn = TryGetPawnOwner();

	ATBG_Player* Player = Cast<ATBG_Player>(pawn);

	if (Player != nullptr)
	{
		Speed = Player->GetVelocity().Size();
		IsJumping = Player->GetCharacterMovement()->IsFalling();
		IsAttacking = Player->IsAttacking();

	}
}

void UTBG_AnimInstance::PlayAttackMontage()
{

	if (Montage_Attack == nullptr)
		return;

	if (Montage_IsPlaying(Montage_Attack))
		return;

	Montage_Play(Montage_Attack);
}

void UTBG_AnimInstance::PlayFieldAttackMontage()
{
	if (Montage_FieldAttack == nullptr)
		return;

	if (Montage_IsPlaying(Montage_FieldAttack))
		return;

	Montage_Play(Montage_FieldAttack);

}

void UTBG_AnimInstance::AnimNotify_Attack_Hit()
{
	if (AttackEvent.IsBound())
		AttackEvent.Broadcast();
}

void UTBG_AnimInstance::AnimNotify_Dead()
{
	//if (DeadEvent.IsBound())
	//	DeadEvent.Broadcast();
}

void UTBG_AnimInstance::AnimNotify_FieldAttack()
{
	if (FieldAttackEvent.IsBound())
		FieldAttackEvent.Broadcast();

}

void UTBG_AnimInstance::JumpToSection(int32 sectionIndex)
{
	FName sectionName = FName(*FString::Printf(TEXT("Section%d"), sectionIndex));

	Montage_JumpToSection(sectionName);
}

