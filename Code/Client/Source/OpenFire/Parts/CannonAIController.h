// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "CannonAIController.generated.h"

/**
 * 
 */
UCLASS()
class OPENFIRE_API ACannonAIController : public AAIController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
};
