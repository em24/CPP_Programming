// Fill out your copyright notice in the Description page of Project Settings.

#include "SpecProj.h"
#include "MyPawn.h"


// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	CameraPivot = CreateDefaultSubobject<USceneComponent>(TEXT("CameraPivot"));
	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurCamera->AttachTo(RootComponent);
	OurCamera->SetRelativeLocation(FVector(-600.0f, 0.0f, 0.0f));
	//OurCamera->SetRelativeRotation(FRotator(-20.0f, 0.0f, 0.0f));
	OurVisibleComponent->AttachTo(RootComponent);
	OurCamera->AttachTo(CameraPivot);

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AMyPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	
	//walk 
	

	CurrentVelocity = CurrentForwardVector + CurrentRightVector;

		

		if(!CurrentVelocity.IsZero())
		{
			FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime * MovementSpeed);

			SetActorLocation(NewLocation);
		}

		float CurrentScale = OurVisibleComponent->GetComponentScale().X;

		//Grow
		if(bGrowing)
		{
			CurrentScale += DeltaTime;
		}
		else
		{
			CurrentScale -= (DeltaTime * 0.5f);
		}
		CurrentScale = FMath::Clamp(CurrentScale, 1.0f, 5.0f);
		OurVisibleComponent->SetWorldScale3D(FVector(CurrentScale));
		
		FVector MyRelativeLocation = (OurVisibleComponent->GetRelativeTransform().GetTranslation());

		
		//Make the visible object stay within the clamped treshold
		MyRelativeLocation.X = FMath::Clamp(MyRelativeLocation.X, -100.0f, 100.0f);
		MyRelativeLocation.Y = FMath::Clamp(MyRelativeLocation.Y, -100.0f, 100.0f);
	

			
		OurVisibleComponent->SetRelativeLocation(MyRelativeLocation);

		// set Camera rotation
		if(!DeltaRotation.IsZero())
		{
			CurrentRotation += DeltaRotation;
			CameraPivot->SetRelativeRotation(CurrentRotation);
		}

		//Set camera height to the height of the visible object
		CameraPivot->SetRelativeLocation(FVector(CameraPivot->RelativeLocation.X, CameraPivot->RelativeLocation.Y, OurVisibleComponent->GetRelativeTransform().GetTranslation().Z));
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("MoveForward", this, &AMyPawn::Move_ForwardAxis);
	InputComponent->BindAxis("MoveRight", this, &AMyPawn::Move_RightAxis);
	InputComponent->BindAction("Grow", IE_Pressed, this, &AMyPawn::StartGrowing);
	InputComponent->BindAction("Grow", IE_Released, this, &AMyPawn::StopGrowing);
	InputComponent->BindAction("Jump", IE_Pressed, this, &AMyPawn::Jump);
	InputComponent->BindAxis("Turn", this, &AMyPawn::TurnRightAxis);
	InputComponent->BindAxis("LookUp", this, &AMyPawn::LookUp);
}

void AMyPawn::TurnRightAxis(float AxisValue)
{
	DeltaRotation.Yaw = AxisValue;
}

void AMyPawn::LookUp(float AxisValue)
{
	DeltaRotation.Pitch = AxisValue;
}

void AMyPawn::Move_ForwardAxis(float AxisValue)
{
	FCurrentForwardVelocity = ((FMath::Cos(CameraPivot->GetComponentRotation().Yaw * 0.0174532925)) * AxisValue);
	FCurrentRightVelocity = ((FMath::Sin(CameraPivot->GetComponentRotation().Yaw * 0.0174532925)) * AxisValue);
	CurrentForwardVector = FVector(FCurrentForwardVelocity,FCurrentRightVelocity,0.0f);
}

void AMyPawn::Move_RightAxis(float AxisValue)
{
	RCurrentForwardVelocity = ((FMath::Cos(1.57079633 + (CameraPivot->GetComponentRotation().Yaw * 0.0174532925))) * AxisValue);
	RCurrentRightVelocity	= ((FMath::Sin(1.57079633 + (CameraPivot->GetComponentRotation().Yaw * 0.0174532925))) * AxisValue);
	CurrentRightVector = FVector(RCurrentForwardVelocity, RCurrentRightVelocity, 0.0f);
}

void AMyPawn::Jump()
{
	OurVisibleComponent->AddForce(FVector(0.0f, 0.0f, JumpHeight));
}

void AMyPawn::StartGrowing()
{
	bGrowing = true;
}
void AMyPawn::StopGrowing()
{
	bGrowing = false;
}


