// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "OpenFireGameMode.generated.h"

/**
 *
 */
UCLASS()
class OPENFIRE_API AOpenFireGameMode : public AGameMode
{
    GENERATED_BODY()

    AOpenFireGameMode();

    virtual void StartPlay() override;
};
