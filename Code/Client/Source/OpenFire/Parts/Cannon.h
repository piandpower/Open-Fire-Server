// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Parts/ShipPart.h"
#include "Cannon.generated.h"

/**
 *
 */
UCLASS()
class OPENFIRE_API ACannon : public AShipPart
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaSeconds) override;

private:
	void Fire();

private:
	UPROPERTY(EditAnywhere)
	FVector InitialVelocity = FVector(300000.f, 0.0f, 50000.0f);

	float FireDelay = 2.0f;
	float ReloadTime = 0.0f;
};
