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
}

void UTouchMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTouchMove::InputTouch(AActor* pTargetActor, uint32 Handle, ETouchType::Type Type, const FVector2D& TouchLocation, FDateTime DeviceTimestamp, uint32 TouchpadIndex)
{
    if (TouchpadIndex == 0)
    {
        switch (Type)
        {
            case ETouchType::Began:
                UE_LOG(LogTemp, Warning, TEXT("TouchMove Began"));
                TargetStartLocation = pTargetActor->GetActorLocation();
                TouchStartLocation = TouchLocation;
                break;

            case ETouchType::Moved:
            {
                auto CurrentLocation = TouchLocation - TouchStartLocation;
                auto TargetCurrentLocatopn = TargetStartLocation;
                TargetCurrentLocatopn.X += CurrentLocation.Y;
                TargetCurrentLocatopn.Y -= CurrentLocation.X;
                pTargetActor->SetActorLocation(TargetCurrentLocatopn);
                UE_LOG(LogTemp, Warning, TEXT("TouchMove Moved %f, %f"), CurrentLocation.X, CurrentLocation.Y);
            }   break;

            case ETouchType::Ended:
                UE_LOG(LogTemp, Warning, TEXT("TouchMove Ended"));
                break;

            default:
                break;
        }
    }
}