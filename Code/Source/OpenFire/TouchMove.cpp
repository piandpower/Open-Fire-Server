// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "TouchMove.h"

UTouchMove::UTouchMove()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    bWantsBeginPlay = true;
    PrimaryComponentTick.bCanEverTick = true;
}

void UTouchMove::BeginPlay()
{
    Super::BeginPlay();

    GetOwner();
}

void UTouchMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTouchMove::InputTouch(uint32 Handle, ETouchType::Type Type, const FVector2D& TouchLocation, FDateTime DeviceTimestamp, uint32 TouchpadIndex)
{
    switch (Type)
    {
        case ETouchType::Began:
            UE_LOG(LogTemp, Warning, TEXT("TouchMove Began: %d"), TouchpadIndex);
            break;
        case ETouchType::Moved:
            UE_LOG(LogTemp, Warning, TEXT("TouchMove Moved"));
            break;
        case ETouchType::Stationary:
            UE_LOG(LogTemp, Warning, TEXT("TouchMove Stationary"));
            break;
        case ETouchType::Ended:
            UE_LOG(LogTemp, Warning, TEXT("TouchMove Ended"));
            break;
        case ETouchType::NumTypes:
            UE_LOG(LogTemp, Warning, TEXT("TouchMove NumTypes"));
            break;
        default:
            break;
    }
}