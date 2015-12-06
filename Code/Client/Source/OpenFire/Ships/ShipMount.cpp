// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "ShipMount.h"


// Sets default values for this component's properties
UShipMount::UShipMount()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    bWantsBeginPlay = true;
    PrimaryComponentTick.bCanEverTick = true;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualAsset(TEXT("/Engine/BasicShapes/Cube"));
    if (VisualAsset.Succeeded())
    {
        SetStaticMesh(VisualAsset.Object);
        SetRelativeScale3D(FVector(1.0f, 1.0f, 0.1f));
    }
}


// Called when the game starts
void UShipMount::BeginPlay()
{
    Super::BeginPlay();

    // ...

}


// Called every frame
void UShipMount::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // ...
}

