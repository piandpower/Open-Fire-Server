// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "CannonFireBTTaskNode.h"

UCannonFireBTTaskNode::UCannonFireBTTaskNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bNotifyTick = true;
}

EBTNodeResult::Type UCannonFireBTTaskNode::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("EBTNodeResult::Type UCannonFireBTTaskNode::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)"));

	return EBTNodeResult::Type::InProgress;
}

void UCannonFireBTTaskNode::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	UE_LOG(LogTemp, Warning, TEXT("void UCannonFireBTTaskNode::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)"));
}
