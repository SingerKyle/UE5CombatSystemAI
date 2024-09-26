// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Enemy_Base.generated.h"

UCLASS()
class COMBATSYSTEMAI_API AEnemy_Base : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy_Base();

	UBehaviorTree* getBehaviorTree() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// behaviour tree
	UPROPERTY(EditAnywhere, Category = "Enemy AI") UBehaviorTree* tree;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
