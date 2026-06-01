// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/TBG_Character.h"
#include "TBG_Enemy.generated.h"

UCLASS()
class TBG_API ATBG_Enemy : public ATBG_Character
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATBG_Enemy();

	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	




	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	TArray<TSubclassOf<ATBG_Enemy>> GetEnemyInfos() const { return EnemyInfos; }
	
	bool IsAttacking() { return IsAttack; }


	UPROPERTY(EditAnywhere, Category = "EnemyInfos")
	TArray<TSubclassOf<ATBG_Enemy>> EnemyInfos;


	UPROPERTY(BlueprintReadOnly, Category = "Animation", meta = (AllowPrivateAccess = "true"))
	bool IsAttack = false;
};
