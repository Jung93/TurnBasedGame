// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TBG_EnemyAnimInstance.generated.h"

DECLARE_MULTICAST_DELEGATE(FEnemyAttackHitEvent);
DECLARE_MULTICAST_DELEGATE(FEnemyDeadEvent);

UCLASS()
class TBG_API UTBG_EnemyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UTBG_EnemyAnimInstance();

	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UFUNCTION()
	void PlayAttackMontage();

	UFUNCTION()
	void AnimNotify_Attack_Hit();

	UFUNCTION()
	void AnimNotify_Dead();

	void JumpToSection(int32 sectionIndex);

	FEnemyAttackHitEvent AttackEvent;
	FEnemyDeadEvent DeadEvent;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State", meta = (AllowPrivateAccess = "true"))
	float Speed = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State", meta = (AllowPrivateAccess = "true"))
	bool IsJumping = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimMontage", meta = (AllowPrivateAccess = "true"))
	class UAnimMontage* Montage_Attack;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State", meta = (AllowPrivateAccess = "true"))
	bool IsDead = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State", meta = (AllowPrivateAccess = "true"))
	bool IsAttacking = false;
};
