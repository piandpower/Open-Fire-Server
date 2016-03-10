#include "OpenFire.h"
#include "WorldGraph.h"
#include "GameObject/Building/Building.h"
#include "WorldGraph/Object.h"

WorldGraph* WorldGraph::instance = nullptr;

WorldGraph* WorldGraph::Instance()
{
	if (instance == nullptr)
	{
		instance = new WorldGraph();
	}

	return instance;
}

void WorldGraph::OnUpdate()
{
	for (const WorldGraph::Node* node : this->nodes)
	{
		for (Object* gameObject : node->objectDatas)
		{
			gameObject->OnUpdate();
		}
	}
}

void WorldGraph::AddNode(int32 Id, FVector Location)
{
	this->nodes.Add(new Node(Id, Location));
}

void WorldGraph::AddEdge(int32 StartNodeId, int32 EndNodeId)
{
	this->edges.Add(new Edge(StartNodeId, EndNodeId));
}

WorldGraph::Node* WorldGraph::GetNode(int32 nodeID)
{
	for (Node* node : this->nodes)
	{
		if (node->id == nodeID)
		{
			return node;
		}
	}

	return nullptr;
}

TArray<WorldGraph::Node*> WorldGraph::GetNearbyNodes(int32 nodeID)
{
	TArray<Node*> nearbyNodes;
	for (Edge* edge : this->edges)
	{
		if (edge->startNodeId == nodeID)
		{
			nearbyNodes.Add(this->GetNode(edge->endNodeId));
		}
	}

	return nearbyNodes;
}

const FVector WorldGraph::GetEdgeLocation(const WorldGraph::Edge* edge)
{
	Node* startNode = this->GetNode(edge->startNodeId);
	Node* endNode = this->GetNode(edge->endNodeId);

	return (startNode->location + endNode->location) * 0.5f;
}

const TArray<WorldGraph::Node*> WorldGraph::GetNodes()
{
	return this->nodes;
}

const TArray<WorldGraph::Edge*> WorldGraph::GetEdges()
{
	return this->edges;
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

	for (const WorldGraph::Node* NodeStart : this->nodes)
	{
		for (const WorldGraph::Node* NodeEnd : this->nodes)
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

void WorldGraph::SpawnBuilding(int32 nodeID, UWorld* world)
{
	auto node = this->GetNode(nodeID);
	node->objectDatas.Add(new Object(nodeID));

	world->SpawnActor<ABuilding>(node->location, FRotator::ZeroRotator);
}

const FVector WorldGraph::GetRandomNodeLocation()
{
	return FVector(FMath::FRandRange(0.0f, 10000.0f), FMath::FRandRange(0.0f, 10000.0f), 0.0f);
}

bool WorldGraph::NodeExistOnRange(const FVector& location, float distance)
{
	float distanceSquared = distance * distance;

	for (const WorldGraph::Node* node : this->nodes)
	{
		float nodeDistanceSquared = FVector::DistSquared(node->location, location);
		if (nodeDistanceSquared < distanceSquared)
		{
			return true;
		}
	}

	return false;
}
