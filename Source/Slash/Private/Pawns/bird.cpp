// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

Abird::Abird()
{
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetCapsuleHalfHeight(20.f);
	Capsule->SetCapsuleRadius(15.f);
	SetRootComponent(Capsule);

	CrowMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CrowMesh"));
	CrowMesh->SetupAttachment(GetRootComponent());

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 300.f;

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(CameraBoom);

	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void Abird::BeginPlay()
{
	Super::BeginPlay();
	
	if(APlayerController* PlayerControlloer = Cast<APlayerController>(GetController()))
	{		
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerControlloer->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(BirdMappingContext, 0);
		}
	}
}

void Abird::MoveForward(float Value)
{
	if (Controller && (Value != 0.f))
	{
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, Value);
	}
}

void Abird::Move(const FInputActionValue& Value)
{
	const float DirectValue = Value.Get<float>();
	if (Controller && (DirectValue != 0.f))
	{
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, DirectValue);
	}
}

void Abird::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisValue = Value.Get<FVector2D>();
	if(GetController())
	{
		AddControllerYawInput(LookAxisValue.X);
		AddControllerPitchInput(LookAxisValue.Y);
	}
}

void Abird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Abird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &Abird::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &Abird::Look);
	}

}

