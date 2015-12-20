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

private:
	ACannon* OwnerCannon = nullptr;
	AShipPart* TargetEnemyPart = nullptr;
};
