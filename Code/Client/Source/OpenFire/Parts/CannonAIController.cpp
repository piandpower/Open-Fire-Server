// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "CannonAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/Composites/BTComposite_SimpleParallel.h"
#include "Parts/CannonAimBTTaskNode.h"
#include "Parts/CannonFireBTTaskNode.h"

void ACannonAIController::BeginPlay()
{
	UBehaviorTree* BehaviorTree = NewObject<UBehaviorTree>();

	UBTComposite_SimpleParallel* BTComposite_SimpleParallel = NewObject<UBTComposite_SimpleParallel>(BehaviorTree);
	BTComposite_SimpleParallel->FinishMode = EBTParallelMode::Type::AbortBackground;
	BTComposite_SimpleParallel->InitializeFromAsset(*BehaviorTree);
	BehaviorTree->RootNode = BTComposite_SimpleParallel;

	UCannonAimBTTaskNode* CannonAimBTTaskNode = NewObject<UCannonAimBTTaskNode>(BehaviorTree);
	const int32 ChildIdx = BTComposite_SimpleParallel->Children.AddZeroed(1);
	BTComposite_SimpleParallel->Children[ChildIdx].ChildTask = CannonAimBTTaskNode;

	UCannonFireBTTaskNode* CannonFireBTTaskNode = NewObject<UCannonFireBTTaskNode>(BehaviorTree);
	const int32 ChildIdx2 = BTComposite_SimpleParallel->Children.AddZeroed(1);
	BTComposite_SimpleParallel->Children[ChildIdx2].ChildTask = CannonFireBTTaskNode;

	RunBehaviorTree(BehaviorTree);
}
