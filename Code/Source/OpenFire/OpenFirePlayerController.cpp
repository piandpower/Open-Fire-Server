// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "OpenFirePlayerController.h"
#include "Utils/TouchMove.h"

void AOpenFirePlayerController::BeginPlay()
{
    Super::BeginPlay();

    pTouchMove = NewObject<UTouchMove>(this);
    pTouchMove->RegisterComponent();
}

void AOpenFirePlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

bool AOpenFirePlayerController::InputTouch(uint32 Handle, ETouchType::Type Type, const FVector2D& TouchLocation, FDateTime DeviceTimestamp, uint32 TouchpadIndex)
{
    bool bResult = Super::InputTouch(Handle, Type, TouchLocation, DeviceTimestamp, TouchpadIndex);

    pTouchMove->InputTouch(GetControlledPawn(), Handle, Type, TouchLocation, DeviceTimestamp, TouchpadIndex);

    return bResult;
}