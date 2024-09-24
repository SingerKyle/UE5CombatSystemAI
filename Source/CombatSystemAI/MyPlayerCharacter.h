// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacterClass.h"
#include "Camera/CameraComponent.h"
#include "InputAction.h"
#include "GameFramework/SpringArmComponent.h"
#include "MyPlayerCharacter.generated.h"


UCLASS()
class COMBATSYSTEMAI_API AMyPlayerCharacter : public ABaseCharacterClass
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyPlayerCharacter();

	// Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input", meta = (AllowPrivateAccess = true)) class UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input", meta = (AllowPrivateAccess = true)) UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input", meta = (AllowPrivateAccess = true)) UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input", meta = (AllowPrivateAccess = true)) UInputAction* LookAction;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// movement
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	// jump
	void StartJump();
	void StopJump();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere) USpringArmComponent* BoomArm;
	UPROPERTY(VisibleAnywhere) UCameraComponent* TPSCamera;

private:
	class UAIPerceptionStimuliSourceComponent* stimulus;

	void setupStimulus();

};
