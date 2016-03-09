#include "OpenFire.h"
#include "WorldGraph.h"

WorldGraph* WorldGraph::instance = nullptr;

WorldGraph* WorldGraph::Instance()
{
	if (instance == nullptr)
	{
		instance = new WorldGraph();
	}

	return instance;
}

void WorldGraph::AddNode(int32 Id, FVector Location)
{
	this->Nodes.Add(new Node(Id, Location));
}

void WorldGraph::AddEdge(int32 StartNodeId, int32 EndNodeId)
{
	this->Edges.Add(new Edge(StartNodeId, EndNodeId));
}

const FVector WorldGraph::GetEdgeLocation(const WorldGraph::Edge* edge) const
{
	const Node* startNode = this->GetNodeByID(edge->startNodeId);
	const Node* endNode = this->GetNodeByID(edge->endNodeId);

	return (startNode->location + endNode->location) * 0.5f;
}

const TArray<WorldGraph::Node*> WorldGraph::GetNodes()
{
	return this->Nodes;
}

const TArray<WorldGraph::Edge*> WorldGraph::GetEdges()
{
	return this->Edges;
}

void WorldGraph::GenerateTestData()
{
	for (int i = 0; i < 100000; ++i)
	{
		auto location = this->GetRandomNodeLocation();
		if (this->NodeExistOnRange(location, 700.0f) == false)
		{
			this->AddNode(i, location);
		}
	}

	for (const WorldGraph::Node* NodeStart: this->Nodes)
	{
		for (const WorldGraph::Node* NodeEnd : this->Nodes)
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

const WorldGraph::Node* WorldGraph::GetNodeByID(int32 id) const
{
	for (const WorldGraph::Node* node : this->Nodes)
	{
		if (node->id == id)
		{
			return node;
		}
	}

	return nullptr;
}

const FVector WorldGraph::GetRandomNodeLocation()
{
	return FVector(FMath::FRandRange(0.0f, 10000.0f), FMath::FRandRange(0.0f, 10000.0f), 0.0f);
}

bool WorldGraph::NodeExistOnRange(const FVector& location, float distance)
{
	float distanceSquared = distance * distance;

	for (const WorldGraph::Node* node : this->Nodes)
	{
		float nodeDistanceSquared = FVector::DistSquared(node->location, location);
		if (nodeDistanceSquared < distanceSquared)
		{
			return true;
		}
	}

	return false;
}
