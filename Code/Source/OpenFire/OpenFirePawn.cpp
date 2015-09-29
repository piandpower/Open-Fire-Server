// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "OpenFirePawn.h"

// Sets default values
AOpenFirePawn::AOpenFirePawn()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AOpenFirePawn::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AOpenFirePawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AOpenFirePawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
    Super::SetupPlayerInputComponent(InputComponent);
}