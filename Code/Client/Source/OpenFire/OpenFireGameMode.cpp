// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "OpenFireGameMode.h"
#include "OpenFirePlayerController.h"
#include "StrongPoint/StrongPoint.h"
#include "StrongPoint/StrongPointEdge.h"
#include "StrongPoint/StrongPointGraph.h"

AOpenFireGameMode::AOpenFireGameMode()
{
	this->PlayerControllerClass = AOpenFirePlayerController::StaticClass();
}

void AOpenFireGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	this->StrongPointGraphInstance = new StrongPointGraph();
	this->StrongPointGraphInstance->GenerateTestData();

	auto Nodes = StrongPointGraphInstance->GetNodes();
	for (const StrongPointGraph::Node* node : StrongPointGraphInstance->GetNodes())
	{
		this->SpawnStrongPoint(node->location);
	}

	for (const StrongPointGraph::Edge* edge : StrongPointGraphInstance->GetEdges())
	{
		this->SpawnStrongPointEdge(this->StrongPointGraphInstance->GetEdgeLocation(edge));
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
