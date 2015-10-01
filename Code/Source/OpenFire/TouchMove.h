// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TouchMove.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OPENFIRE_API UTouchMove : public UActorComponent
{
    GENERATED_BODY()

public:
    UTouchMove();

    virtual void BeginPlay() override;

    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    void InputTouch(AActor* pTargetActor, uint32 Handle, ETouchType::Type Type, const FVector2D& TouchLocation, FDateTime DeviceTimestamp, uint32 TouchpadIndex);

private:
    FVector     TargetStartLocation;
    FVector2D   TouchStartLocation;
};