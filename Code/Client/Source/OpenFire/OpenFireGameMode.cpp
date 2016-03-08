// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "OpenFireGameMode.h"
#include "StrongPoint/StrongPoint.h"
#include "StrongPoint/StrongPointGraph.h"

void AOpenFireGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	this->StrongPointGraphInstance = new StrongPointGraph();
	this->StrongPointGraphInstance->GenerateTestData();

	auto Nodes = StrongPointGraphInstance->GetNodes();

	for (const StrongPointGraph::Node& Node : Nodes)
	{
		this->SpawnStrongPoint(Node.Location);
	}
}

void AOpenFireGameMode::SpawnStrongPoint(FVector Location)
{
	this->GetWorld()->SpawnActor<AStrongPoint>(Location, FRotator::ZeroRotator);
}
