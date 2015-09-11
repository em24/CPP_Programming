// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class SPECPROJ_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
AMyPawn();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* OurVisibleComponent;

	UPROPERTY(EditAnywhere)
		USceneComponent* CameraPivot;

	UPROPERTY(EditAnywhere)
		float MovementSpeed = 500;

	UPROPERTY(EditAnywhere)
		float JumpHeight = 1000000.0f;

	UPROPERTY(EditAnywhere)
		FVector CameraPosition;

	//Input
	void Move_ForwardAxis(float AxisValue);
	void Move_RightAxis(float AxisValue);
	void StartGrowing();
	void StopGrowing();
	void Jump();
	void TurnRightAxis(float AxisValue);
	void LookUp(float AxisValue);

	FRotator CurrentRotation;
	FRotator DeltaRotation;
	FVector CurrentVelocity;
	FVector CurrentRightVector;
	FVector CurrentForwardVector;

	float FCurrentForwardVelocity;
	float FCurrentRightVelocity;
	float RCurrentForwardVelocity;
	float RCurrentRightVelocity;

	bool bGrowing;

};
