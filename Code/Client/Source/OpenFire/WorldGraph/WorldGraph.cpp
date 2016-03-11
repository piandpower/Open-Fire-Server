#include "OpenFire.h"
#include "WorldGraph.h"
#include "WorldGraph/WorldGraphNode.h"
#include "GameObject/Building/Castle.h"
#include "WorldGraph/ObjectData/Building/CastleData.h"
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
	for (ObjectData* gameObject : this->objects)
	{
		gameObject->OnUpdate();
	}
}

void WorldGraph::AddNode(int32 Id, FVector Location)
{
	this->nodes.Add(new WorldGraphNode(Id, Location));
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

WorldGraphNode* WorldGraph::GetNode(int32 nodeID)
{
	for (WorldGraphNode* node : this->nodes)
	{
		if (node->nodeID == nodeID)
		{
			return node;
		}
	}

	return nullptr;
}

TArray<WorldGraphNode*> WorldGraph::GetNearbyNodes(int32 nodeID)
{
	TArray<WorldGraphNode*> nearbyNodes;
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
	WorldGraphNode* startNode = this->GetNode(edge->startNodeId);
	WorldGraphNode* endNode = this->GetNode(edge->endNodeId);

	return (startNode->location + endNode->location) * 0.5f;
}

const TArray<WorldGraphNode*> WorldGraph::GetNodes()
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

	for (const WorldGraphNode* NodeStart : this->nodes)
	{
		for (const WorldGraphNode* NodeEnd : this->nodes)
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

void WorldGraph::SpawnCastle(int32 nodeID)
{
	const int32 objectID = this->GenerateObjectID();
	CastleData* castleData = new CastleData();
	castleData->Initialize(objectID, nodeID);
	this->objects.Add(castleData);

	WorldGraphNode* node = this->GetNode(nodeID);
	node->AddObject(objectID, castleData);

	ACastle* castle = this->world->SpawnActor<ACastle>(node->location, FRotator::ZeroRotator);
	castle->Initialize(objectID);
}

void WorldGraph::SpawnWorker(int32 nodeID)
{
	const int32 objectID = this->GenerateObjectID();
	WorkerData* workerData = new WorkerData();
	workerData->Initialize(objectID, nodeID);
	this->objects.Add(workerData);

	WorldGraphNode* node = this->GetNode(nodeID);
	node->AddObject(objectID, workerData);

	AWorker* worker = this->world->SpawnActor<AWorker>(node->location, FRotator::ZeroRotator);
	worker->Initialize(objectID);
}

void WorldGraph::MoveObject(int objectID, int32 nodeID)
{
	ObjectData* objectData = this->GetObject(objectID);
	objectData->SetNodeID(nodeID);

	WorldGraphNode* startNode = this->GetNode(objectData->nodeID);
	startNode->RemoveObject(objectID);
	
	WorldGraphNode* endNode = this->GetNode(nodeID);
	endNode->AddObject(objectID, objectData);
}

const FVector WorldGraph::GetRandomNodeLocation()
{
	return FVector(FMath::FRandRange(0.0f, 10000.0f), FMath::FRandRange(0.0f, 10000.0f), 0.0f);
}

bool WorldGraph::NodeExistOnRange(const FVector& location, float distance)
{
	float distanceSquared = distance * distance;

	for (const WorldGraphNode* node : this->nodes)
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
