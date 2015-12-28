// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "CannonAIController.generated.h"

class ACannon;
class AShipPart;

UCLASS()
class OPENFIRE_API ACannonAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Possess(APawn* InPawn) override;

	UFUNCTION(BlueprintCallable, Category = CannonAIController)
	TArray<AShipPart*> Search();

	UFUNCTION(BlueprintCallable, Category = CannonAIController)
	AShipPart* SelectTarget(const TArray<AShipPart*>& Targets);

	UFUNCTION(BlueprintCallable, Category = CannonAIController)
	void Aim(AShipPart* Target);

private:
	void AimYaw(const FVector& TargetVector);
	void AimPitch(const FVector& TargetVector);

	float GetPitchAngle(const float& Speed, const float& TargetDistance, const float& TargetHeight);

private:
	ACannon* OwnerCannon = nullptr;
};
