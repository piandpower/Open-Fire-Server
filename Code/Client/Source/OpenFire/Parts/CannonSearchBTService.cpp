// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "CannonSearchBTService.h"

void UCannonSearchBTService::OnSearchStart(FBehaviorTreeSearchData & SearchData)
{
	UE_LOG(LogTemp, Warning, TEXT("void UCannonSearchBTService::OnSearchStart(FBehaviorTreeSearchData & SearchData)"));
}

void UCannonSearchBTService::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	UBTService::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UE_LOG(LogTemp, Warning, TEXT("void UCannonSearchBTService::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)"));
}
