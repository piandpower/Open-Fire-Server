#include "OpenFire.h"
#include "WorldGraph.h"
#include "Type/MissionType.h"
#include "WorldGraph/StrongPointData.h"
#include "GameObject/Building/Mine.h"
#include "WorldGraph/ObjectData/Building/MineData.h"
#include "GameObject/Building/Farm.h"
#include "WorldGraph/ObjectData/Building/FarmData.h"
#include "GameObject/Building/Castle.h"
#include "WorldGraph/ObjectData/Building/CastleData.h"
#include "GameObject/Unit/Worker.h"
#include "WorldGraph/ObjectData/Unit/WorkerData.h"
#include "GameObject/Hero/Hero.h"
#include "WorldGraph/ObjectData/Hero/HeroData.h"
#include "GameObject/Resource/Gold.h"
#include "WorldGraph/ObjectData/Resource/GoldData.h"

void WorldGraph::Initialize(UWorld* world)
{
	this->world = world;
	this->strongPointDatas.Empty();
	this->edges.Empty();
	this->objectDatas.Empty();
}

void WorldGraph::OnUpdate()
{
	for (ObjectData* gameObject : this->objectDatas)
	{
		gameObject->OnUpdate();
	}
}

void WorldGraph::AddEdge(int32 StartNodeId, int32 EndNodeId)
{
	this->edges.Add(new Edge(StartNodeId, EndNodeId));
}

ObjectData* WorldGraph::GetObject(int32 objectID)
{
	for (ObjectData* object : this->objectDatas)
	{
		if (object->objectID == objectID)
		{
			return object;
		}
	}

	return nullptr;
}

StrongPointData* WorldGraph::GetNode(int32 nodeID)
{
	for (StrongPointData* node : this->strongPointDatas)
	{
		if (node->strongPointID == nodeID)
		{
			return node;
		}
	}

	return nullptr;
}

TArray<StrongPointData*> WorldGraph::GetNearbyNodes(int32 nodeID)
{
	TArray<StrongPointData*> nearbyNodes;
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
	StrongPointData* startNode = this->GetNode(edge->startNodeId);
	StrongPointData* endNode = this->GetNode(edge->endNodeId);

	return (startNode->location + endNode->location) * 0.5f;
}

const TArray<StrongPointData*> WorldGraph::GetStrongPointDatas()
{
	return this->strongPointDatas;
}

const TArray<WorldGraph::Edge*> WorldGraph::GetEdges()
{
	return this->edges;
}

const TArray<ObjectData*> WorldGraph::GetObjectDatas()
{
	return this->objectDatas;
}

void WorldGraph::GenerateTestData()
{
	this->GenerateTestNodeAndEdges();
	this->GenerateTestHeroes();
}

void WorldGraph::AddStrongPointData(int32 id, FVector location)
{
	this->strongPointDatas.Add(new StrongPointData(id, location));
}

void WorldGraph::AddObject(int32 objectID, int32 strongPointID, ObjectDataType type)
{
	ObjectData* objectData = new ObjectData();
	objectData->Initialize(objectID, strongPointID, type);
	this->objectDatas.Add(objectData);
}

void WorldGraph::SpawnHero(int32 nodeID, const MissionValues& missionValues)
{
	const int32 objectID = this->GenerateObjectID();
	HeroData* heroData = new HeroData();
	heroData->Initialize(objectID, nodeID, ObjectDataType::Unit);
	heroData->SetMissionValues(missionValues);
	this->objectDatas.Add(heroData);

	StrongPointData* node = this->GetNode(nodeID);
	node->AddObject(heroData);

	AHero* hero = this->world->SpawnActor<AHero>(node->GetObjectLocation(objectID), FRotator::ZeroRotator);
	hero->Initialize(objectID, heroData->GetMissionColor());
}

void WorldGraph::SpawnCastle(int32 nodeID)
{
	const int32 objectID = this->GenerateObjectID();
	CastleData* castleData = new CastleData();
	castleData->Initialize(objectID, nodeID, ObjectDataType::Building);
	this->objectDatas.Add(castleData);

	StrongPointData* node = this->GetNode(nodeID);
	node->SetBuilding(castleData);

	ACastle* castle = this->world->SpawnActor<ACastle>(node->location, FRotator::ZeroRotator);
	castle->Initialize(objectID);
}

void WorldGraph::SpawnFarm(int32 nodeID)
{
	const int32 objectID = this->GenerateObjectID();
	FarmData* farmData = new FarmData();
	farmData->Initialize(objectID, nodeID, ObjectDataType::Building);
	this->objectDatas.Add(farmData);

	StrongPointData* node = this->GetNode(nodeID);
	node->SetBuilding(farmData);

	AFarm* farm = this->world->SpawnActor<AFarm>(node->location, FRotator::ZeroRotator);
	farm->Initialize(objectID);
}

void WorldGraph::SpawnMine(int32 nodeID)
{
	const int32 objectID = this->GenerateObjectID();
	MineData* mineData = new MineData();
	mineData->Initialize(objectID, nodeID, ObjectDataType::Building);
	this->objectDatas.Add(mineData);

	StrongPointData* node = this->GetNode(nodeID);
	node->SetBuilding(mineData);

	AMine* mine = this->world->SpawnActor<AMine>(node->location, FRotator::ZeroRotator);
	mine->Initialize(objectID);
}

void WorldGraph::SpawnWorker(int32 nodeID)
{
	const int32 objectID = this->GenerateObjectID();
	WorkerData* workerData = new WorkerData();
	workerData->Initialize(objectID, nodeID, ObjectDataType::Unit);
	this->objectDatas.Add(workerData);

	StrongPointData* node = this->GetNode(nodeID);
	node->AddObject(workerData);

	AWorker* worker = this->world->SpawnActor<AWorker>(node->GetObjectLocation(objectID), FRotator::ZeroRotator);
	worker->Initialize(objectID);
}

void WorldGraph::SpawnGold(int32 nodeID)
{
	const int32 objectID = this->GenerateObjectID();
	GoldData* goldData = new GoldData();
	goldData->Initialize(objectID, nodeID, ObjectDataType::Resource);
	this->objectDatas.Add(goldData);

	StrongPointData* node = this->GetNode(nodeID);
	node->AddResource(goldData);

	AGold* gold = this->world->SpawnActor<AGold>(node->GetResourceLocation(objectID), FRotator::ZeroRotator);
	gold->Initialize(objectID);
}

void WorldGraph::MoveObject(int objectID, int32 nodeID)
{
	ObjectData* objectData = this->GetObject(objectID);

	StrongPointData* startNode = this->GetNode(objectData->strongPointID);
	startNode->RemoveObject(objectID);

	StrongPointData* endNode = this->GetNode(nodeID);
	endNode->AddObject(objectData);

	objectData->SetNodeID(nodeID);
}

const FVector WorldGraph::GetRandomNodeLocation()
{
	float halfRange = 5000.0f;
	return FVector(FMath::FRandRange(-halfRange, +halfRange), FMath::FRandRange(-halfRange, halfRange), 0.0f);
}

bool WorldGraph::NodeExistOnRange(const FVector& location, float distance)
{
	float distanceSquared = distance * distance;

	for (const StrongPointData* node : this->strongPointDatas)
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

const int32 WorldGraph::GetRandomNodeID() const
{
	const StrongPointData* randomNode = this->strongPointDatas[FMath::RandRange(0, this->strongPointDatas.Num() - 1)];
	return randomNode->strongPointID;
}

void WorldGraph::GenerateTestNodeAndEdges()
{
	for (int i = 0; i < 100000; ++i)
	{
		auto location = this->GetRandomNodeLocation();
		if (this->NodeExistOnRange(location, 700.0f) == false)
		{
			this->AddStrongPointData(i, location);
		}
	}

	for (const StrongPointData* NodeStart : this->strongPointDatas)
	{
		for (const StrongPointData* NodeEnd : this->strongPointDatas)
		{
			if (NodeStart->strongPointID == NodeEnd->strongPointID)
			{
				continue;
			}

			if (FVector::DistSquared(NodeStart->location, NodeEnd->location) <= (700.0f * 700.0f * 2.0f))
			{
				this->AddEdge(NodeStart->strongPointID, NodeEnd->strongPointID);
			}
		}
	}
}

void WorldGraph::GenerateTestHeroes()
{
	for (int i = 0; i < 30; ++i)
	{
		const int32 nodeID = this->GetRandomNodeID();
		this->SpawnHero(nodeID, this->GetRandomMissionValues());
	}
}

MissionValues WorldGraph::GetRandomMissionValues()
{
	return MissionValues(FMath::RandRange(0, 100), FMath::RandRange(0, 100), FMath::RandRange(0, 100));
}
