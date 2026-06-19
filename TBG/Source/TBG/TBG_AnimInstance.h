// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TBG_AnimInstance.generated.h"

/**
 * 
 */

DECLARE_MULTICAST_DELEGATE(FAttackHitEvent);
DECLARE_MULTICAST_DELEGATE(FFieldAttackHitEvent);
DECLARE_MULTICAST_DELEGATE(FDeadEvent);

UCLASS()
class TBG_API UTBG_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UTBG_AnimInstance();

	virtual void NativeUpdateAnimation(float DeltaTime);

	UFUNCTION()
	void PlayAttackMontage();

	UFUNCTION()
	void PlayFieldAttackMontage();

	UFUNCTION()
	void AnimNotify_Attack_Hit();

	UFUNCTION()
	void AnimNotify_Dead();

	UFUNCTION()
	void AnimNotify_FieldAttack();

	void JumpToSection(int32 sectionIndex);


	FAttackHitEvent AttackEvent;
	FDeadEvent DeadEvent;
	FFieldAttackHitEvent FieldAttackEvent;


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State", meta = (AllowPrivateAccess = "true"))
	float Speed = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State", meta = (AllowPrivateAccess = "true"))
	bool IsJumping = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimMontage", meta = (AllowPrivateAccess = "true"))
	class UAnimMontage* Montage_Attack;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimMontage", meta = (AllowPrivateAccess = "true"))
	class UAnimMontage* Montage_FieldAttack;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Blend", meta = (AllowPrivateAccess = "true"))
	float Vertical;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Blend", meta = (AllowPrivateAccess = "true"))
	float Horizontal;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State", meta = (AllowPrivateAccess = "true"))
	bool IsDead = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State", meta = (AllowPrivateAccess = "true"))
	bool IsAttacking = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State", meta = (AllowPrivateAccess = "true"))
	bool IsInBattle = false;
};
