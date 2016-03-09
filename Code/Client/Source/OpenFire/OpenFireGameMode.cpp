// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "OpenFireGameMode.h"
#include "OpenFirePlayerController.h"
#include "StrongPoint/StrongPoint.h"
#include "StrongPoint/StrongPointEdge.h"
#include "WorldGraph/WorldGraph.h"

AOpenFireGameMode::AOpenFireGameMode()
{
	this->PlayerControllerClass = AOpenFirePlayerController::StaticClass();
}

void AOpenFireGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	this->worldGraph = new WorldGraph();
	this->worldGraph->GenerateTestData();

	for (const WorldGraph::Node* node : worldGraph->GetNodes())
	{
		this->SpawnStrongPoint(node->location);
	}

	for (const WorldGraph::Edge* edge : worldGraph->GetEdges())
	{
		this->SpawnStrongPointEdge(this->worldGraph->GetEdgeLocation(edge));
	}
}

void AOpenFireGameMode::SpawnStrongPoint(FVector Location)
{
	this->GetWorld()->SpawnActor<AStrongPoint>(Location, FRotator::ZeroRotator);
}

void AOpenFireGameMode::SpawnStrongPointEdge(FVector Location)
{
	this->GetWorld()->SpawnActor<AStrongPointEdge>(Location, FRotator::ZeroRotator);
}
