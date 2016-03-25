// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "OpenFireGameMode.h"
#include "OpenFirePlayerController.h"
#include "GameObject/StrongPoint/StrongPoint.h"
#include "GameObject/StrongPoint/StrongPointEdge.h"
#include "WorldGraph/WorldGraph.h"
#include "WorldGraph/WorldGraphNode.h"
#include "Manager/TimeManager.h"
#include "Manager/GameObjectManager.h"

const float updateSeconds = 5.0f;

AOpenFireGameMode::AOpenFireGameMode()
{
	this->PlayerControllerClass = AOpenFirePlayerController::StaticClass();
}

void AOpenFireGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	GameObjectManager::Instance()->Initialize(this->GetWorld());

	WorldGraph::Instance()->Initialize(this->GetWorld());

	WorldGraph::Instance()->GenerateTestData();

	for (const WorldGraph::Edge* edge : WorldGraph::Instance()->GetEdges())
	{
		this->SpawnStrongPointEdge(WorldGraph::Instance()->GetEdgeLocation(edge));
	}
}

void AOpenFireGameMode::Tick(float DeltaSeconds)
{
	TimeManager::Instance()->AddSeconds(DeltaSeconds);

	float remainingSeconds = TimeManager::Instance()->GetRemainingSeconds();
	if (remainingSeconds < 0.0f)
	{
		TimeManager::Instance()->RewindSeconds();

		WorldGraph::Instance()->OnUpdate();
		GameObjectManager::Instance()->OnUpdate();
	}
}

void AOpenFireGameMode::SpawnStrongPoint(int32 nodeID, FVector Location)
{
	AStrongPoint* strongPoint = this->GetWorld()->SpawnActor<AStrongPoint>(Location, FRotator::ZeroRotator);
	strongPoint->Initialize(nodeID);
}

void AOpenFireGameMode::SpawnStrongPointEdge(FVector Location)
{
	this->GetWorld()->SpawnActor<AStrongPointEdge>(Location, FRotator::ZeroRotator);
}
