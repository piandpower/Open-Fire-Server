// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "CannonAimBTTaskNode.h"

UCannonAimBTTaskNode::UCannonAimBTTaskNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bNotifyTick = true;
}

EBTNodeResult::Type UCannonAimBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("EBTNodeResult::Type UCannonAimBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)"));

	return EBTNodeResult::Type::InProgress;
}

void UCannonAimBTTaskNode::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	UE_LOG(LogTemp, Warning, TEXT("void UCannonAimBTTaskNode::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)"));
}
