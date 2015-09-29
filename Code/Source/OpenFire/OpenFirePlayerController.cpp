// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "OpenFirePlayerController.h"
#include "TouchMove.h"

void AOpenFirePlayerController::BeginPlay()
{
    Super::BeginPlay();

    UTouchMove* pTouchMove = NewObject<UTouchMove>(this);
    pTouchMove->RegisterComponent();
}

void AOpenFirePlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}