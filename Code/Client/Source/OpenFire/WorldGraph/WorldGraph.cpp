#include "OpenFire.h"
#include "WorldGraph.h"
#include "GameObject/Building/Building.h"
#include "WorldGraph/ObjectData/Building/BuildingData.h"
#include "GameObject/Unit/Worker.h"
#include "WorldGraph/ObjectData/Unit/WorkerData.h"

WorldGraph* WorldGraph::instance = nullptr;

WorldGraph* WorldGraph::Instance()
{
	if (instance == nullptr)
	{
		instance = new WorldGraph();
	}

	return instance;
}

void WorldGraph::Initialize(UWorld* world)
{
	this->world = world;
}

void WorldGraph::OnUpdate()
{
	for (const WorldGraph::Node* node : this->nodes)
	{
		for (ObjectData* gameObject : node->objectDatas)
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

ObjectData* WorldGraph::GetObject(int32 objectID)
{
	for (ObjectData* object : this->objects)
	{
		if (object->objectID == objectID)
		{
			return object;
		}
	}

	return nullptr;
}

WorldGraph::Node* WorldGraph::GetNode(int32 nodeID)
{
	for (Node* node : this->nodes)
	{
		if (node->nodeID == nodeID)
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
			if (NodeStart->nodeID == NodeEnd->nodeID)
			{
				continue;
			}

			if (FVector::DistSquared(NodeStart->location, NodeEnd->location) <= (700.0f * 700.0f * 2.0f))
			{
				this->AddEdge(NodeStart->nodeID, NodeEnd->nodeID);
			}
		}
	}
}

void WorldGraph::SpawnBuilding(int32 nodeID)
{
	const int32 objectID = this->GenerateObjectID();
	BuildingData* buildingData = new BuildingData();
	buildingData->Initialize(objectID, nodeID);
	this->objects.Add(buildingData);

	Node* node = this->GetNode(nodeID);
	node->objectDatas.Add(buildingData);

	ABuilding* building = this->world->SpawnActor<ABuilding>(node->location, FRotator::ZeroRotator);
	building->Initialize(objectID);
}

void WorldGraph::SpawnWorker(int32 nodeID)
{
	const int32 objectID = this->GenerateObjectID();
	WorkerData* workerData = new WorkerData();
	workerData->Initialize(objectID, nodeID);
	this->objects.Add(workerData);

	Node* node = this->GetNode(nodeID);
	node->objectDatas.Add(workerData);

	AWorker* building = this->world->SpawnActor<AWorker>(node->location, FRotator::ZeroRotator);
	building->Initialize(objectID);
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

const int32 WorldGraph::GenerateObjectID() const
{
	static int32 id = 0;
	++id;
	return id;
}
