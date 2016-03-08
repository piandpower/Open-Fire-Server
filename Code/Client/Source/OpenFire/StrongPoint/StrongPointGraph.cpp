#include "OpenFire.h"
#include "StrongPointGraph.h"

StrongPointGraph::StrongPointGraph()
{
}

StrongPointGraph::~StrongPointGraph()
{
}

void StrongPointGraph::AddNode(int32 Id, FVector Location)
{
	this->Nodes.Add(Node(Id, Location));
}

void StrongPointGraph::AddEdge(int32 Id, int32 StartNodeId, int32 EndNodeId)
{
	this->Edges.Add(Edge(Id, StartNodeId, EndNodeId));
}

const TArray<StrongPointGraph::Node>& StrongPointGraph::GetNodes()
{
	return this->Nodes;
}

void StrongPointGraph::GenerateTestData()
{
	for (int i = 0; i < 100; ++i)
	{
		this->AddNode(i, FVector(FMath::FRandRange(0.0f, 10000.0f), FMath::FRandRange(0.0f, 10000.0f), 0.0f));
	}
}
