#pragma once

class ObjectData;
class MissionValues;
class WorldGraphNode;
enum class WorldGraphNodeType;

class OPENFIRE_API WorldGraph
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
	static WorldGraph* instance;

	UWorld* world = nullptr;

	TArray<WorldGraphNode*> nodes;
	TArray<Edge*> edges;
	TArray<ObjectData*> objects;

private:
	WorldGraph() {};
	WorldGraph(WorldGraph const&) {};
	WorldGraph& operator= (WorldGraph const&) { return *this; };

public:
	static WorldGraph* Instance();

	void Initialize(UWorld* world);

	void OnUpdate();

	void AddEdge(int32 StartNodeId, int32 EndNodeId);

	ObjectData* GetObject(int32 objectID);

	WorldGraphNode* GetNode(int32 nodeID);
	TArray<WorldGraphNode*> GetNearbyNodes(int32 nodeID);

	const FVector GetEdgeLocation(const WorldGraph::Edge* edge);

	const TArray<WorldGraphNode*> GetNodes();
	const TArray<WorldGraph::Edge*> GetEdges();

	void GenerateTestData();

	void SpawnNode(int32 id, FVector location, WorldGraphNodeType type);

	void SpawnHero(int32 nodeID, const MissionValues& missionValues);

	void SpawnCastle(int32 nodeID);
	void SpawnFarm(int32 nodeID);

	void SpawnWorker(int32 nodeID);

	void MoveObject(int objectID, int32 nodeID);

private:
	const FVector GetRandomNodeLocation();
	bool NodeExistOnRange(const FVector& location, float distance);
	const int32 GenerateObjectID() const;
	WorldGraphNodeType GetRandomNodeType();

	const int32 GetRandomNodeID() const;

	void GenerateTestNodeAndEdges();
	void GenerateTestHeroes();

	MissionValues GetRandomMissionValues();
};
