// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ShipPart.generated.h"

UCLASS()
class OPENFIRE_API AShipPart : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AShipPart();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Called every frame
    virtual void Tick(float DeltaSeconds) override;

    float Hp        = 0.0f;
    float Force     = 0.0f;
    float Torque    = 0.0f;
    float Mass      = 0.0f;
};
