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
	for (int i = 0; i < 100000; ++i)
	{
		auto location = this->GetRandomNodeLocation();
		if (this->NodeExistOnRange(location, 700.0f) == false)
		{
			this->AddNode(i, location);
		}
	}

	for (const StrongPointGraph::Node* NodeStart: this->Nodes)
	{
		for (const StrongPointGraph::Node* NodeEnd : this->Nodes)
		{
			if (NodeStart->id == NodeEnd->id)
			{
				continue;
			}

			if (FVector::DistSquared(NodeStart->location, NodeEnd->location) <= (700.0f * 700.0f * 2.0f))
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

const FVector StrongPointGraph::GetRandomNodeLocation()
{
	return FVector(FMath::FRandRange(0.0f, 10000.0f), FMath::FRandRange(0.0f, 10000.0f), 0.0f);
}

bool StrongPointGraph::NodeExistOnRange(const FVector& location, float distance)
{
	float distanceSquared = distance * distance;

	for (const StrongPointGraph::Node* node : this->Nodes)
	{
		float nodeDistanceSquared = FVector::DistSquared(node->location, location);
		if (nodeDistanceSquared< distanceSquared)
		{
			return true;
		}
	}

	return false;
}
