// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/TBG_Character.h"
#include "Camera/CameraComponent.h"
#include "TBG_Enemy.generated.h"

UCLASS()
class TBG_API ATBG_Enemy : public ATBG_Character
{
	GENERATED_BODY()

public:
	ATBG_Enemy();

	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;

public:	


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	TArray<TSubclassOf<ATBG_Enemy>> GetEnemyInfos() const { return EnemyInfos; }
	
	bool IsAttacking() { return IsAttack; }


	UPROPERTY(EditAnywhere, Category = "EnemyInfos")
	TArray<TSubclassOf<ATBG_Enemy>> EnemyInfos;

	UPROPERTY(BlueprintReadOnly, Category = "Animation", meta = (AllowPrivateAccess = "true"))
	bool IsAttack = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* TargetingCamera;
};
