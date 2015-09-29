// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "OpenFirePlayerController.generated.h"

class UTouchMove;

UCLASS()
class OPENFIRE_API AOpenFirePlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;

    virtual bool InputTouch(uint32 Handle, ETouchType::Type Type, const FVector2D& TouchLocation, FDateTime DeviceTimestamp, uint32 TouchpadIndex) override;

private:
    UTouchMove* pTouchMove = nullptr;
};