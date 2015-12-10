// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTService.h"
#include "CannonSearchBTService.generated.h"

/**
 * 
 */
UCLASS()
class OPENFIRE_API UCannonSearchBTService : public UBTService
{
	GENERATED_BODY()
	
	virtual void OnSearchStart(FBehaviorTreeSearchData& SearchData) override;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
