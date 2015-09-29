// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "OpenFirePlayerController.generated.h"

/**
 *
 */
UCLASS()
class OPENFIRE_API AOpenFirePlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;
};