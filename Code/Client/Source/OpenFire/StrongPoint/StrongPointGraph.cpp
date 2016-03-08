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
	this->Nodes.Add(new Node(Id, Location));
}

void StrongPointGraph::AddEdge(int32 StartNodeId, int32 EndNodeId)
{
	this->Edges.Add(new Edge(StartNodeId, EndNodeId));
}

const FVector StrongPointGraph::GetEdgeLocation(const StrongPointGraph::Edge* edge) const
{
	const Node* startNode = this->GetNodeByID(edge->startNodeId);
	const Node* endNode = this->GetNodeByID(edge->endNodeId);

	return (startNode->location + endNode->location) * 0.5f;
}

const TArray<StrongPointGraph::Node*> StrongPointGraph::GetNodes()
{
	return this->Nodes;
}

const TArray<StrongPointGraph::Edge*> StrongPointGraph::GetEdges()
{
	return this->Edges;
}

void StrongPointGraph::GenerateTestData()
{
	for (int i = 0; i < 100; ++i)
	{
		this->AddNode(i, FVector(FMath::FRandRange(0.0f, 10000.0f), FMath::FRandRange(0.0f, 10000.0f), 0.0f));
	}

	for (const StrongPointGraph::Node* NodeStart: this->Nodes)
	{
		for (const StrongPointGraph::Node* NodeEnd : this->Nodes)
		{
			if (NodeStart->id == NodeEnd->id)
			{
				continue;
			}

			if (FVector::DistSquared(NodeStart->location, NodeEnd->location) <= 1000000.0f)
			{
				this->AddEdge(NodeStart->id, NodeEnd->id);
			}
		}
	}
}

const StrongPointGraph::Node* StrongPointGraph::GetNodeByID(int32 id) const
{
	for (const StrongPointGraph::Node* node : this->Nodes)
	{
		if (node->id == id)
		{
			return node;
		}
	}

	return nullptr;
}
