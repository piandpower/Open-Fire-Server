#pragma once

#include "Framework/Singleton.h"
#include "WorldGraph/StrongPointData.h"

class ObjectData;
class MissionValues;
enum class ObjectDataType;

class OPENFIRE_API WorldGraph : public Singleton<WorldGraph>
{
public:
	struct Edge
	{
		Edge(int32 startNodeId, int32 endNodeId)
		{
			this->startNodeId = startNodeId;
			this->endNodeId = endNodeId;
		};

		int32 startNodeId;
		int32 endNodeId;
	};

private:
	UWorld* world = nullptr;

	TArray<StrongPointData> strongPointDatas;
	TArray<Edge*> edges;
	TArray<ObjectData*> objectDatas;

public:
	void Initialize(UWorld* world);

	void OnUpdate();

	void AddEdge(int32 StartNodeId, int32 EndNodeId);

	ObjectData* GetObject(int32 objectID);

	StrongPointData* GetNode(int32 nodeID);
	TArray<StrongPointData*> GetNearbyNodes(int32 nodeID);

	const FVector GetEdgeLocation(const WorldGraph::Edge* edge);

	const TArray<StrongPointData>& GetStrongPointDatas();
	const TArray<WorldGraph::Edge*> GetEdges();
	const TArray<ObjectData*> GetObjectDatas();

	void AddStrongPointData(int32 id, FVector location);

	void AddObject(int32 objectID, int32 strongPointID, ObjectDataType type);

	void SpawnHero(int32 nodeID, const MissionValues& missionValues);

	void SpawnCastle(int32 nodeID);
	void SpawnFarm(int32 nodeID);
	void SpawnMine(int32 nodeID);

	void SpawnWorker(int32 nodeID);

	void SpawnGold(int32 nodeID);

	void MoveObject(int objectID, int32 nodeID);

private:
	const FVector GetRandomNodeLocation();
	bool NodeExistOnRange(const FVector& location, float distance);
	const int32 GenerateObjectID() const;

	const int32 GetRandomNodeID() const;

	MissionValues GetRandomMissionValues();
};
