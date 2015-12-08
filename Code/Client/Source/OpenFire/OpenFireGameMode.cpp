// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "OpenFireGameMode.h"
#include "Helpers/JsonHelper.h"
#include "Helpers/ShipHelper.h"
#include "OpenFirePawn.h"
#include "OpenFirePlayerController.h"

AOpenFireGameMode::AOpenFireGameMode()
{
    DefaultPawnClass = AOpenFirePawn::StaticClass();
    PlayerControllerClass = AOpenFirePlayerController::StaticClass();
}

void AOpenFireGameMode::StartPlay()
{
    Super::StartPlay();
}