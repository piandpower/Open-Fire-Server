#pragma once

class Object;

class OPENFIRE_API WorldGraph
{
public:
	struct Node
	{
		Node(int32 id, FVector location)
		{
			this->id = id;
			this->location = location;
		};

		int32 id;
		FVector location;
		TArray<Object*> objectDatas;
	};

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

	TArray<Node*> nodes;
	TArray<Edge*> edges;
	TArray<Object*> objects;

private:
	WorldGraph() {};
	WorldGraph(WorldGraph const&) {};
	WorldGraph& operator= (WorldGraph const&) { return *this; };

public:
	static WorldGraph* Instance();

	void OnUpdate();

	void AddNode(int32 Id, FVector Location);
	void AddEdge(int32 StartNodeId, int32 EndNodeId);

	Object* GetObject(int32 objectID);

	Node* GetNode(int32 nodeID);
	TArray<Node*> GetNearbyNodes(int32 nodeID);

	const FVector GetEdgeLocation(const WorldGraph::Edge* edge);

	const TArray<WorldGraph::Node*> GetNodes();
	const TArray<WorldGraph::Edge*> GetEdges();

	void GenerateTestData();

	void SpawnBuilding(int32 nodeID, UWorld* world);

private:
	const FVector GetRandomNodeLocation();
	bool NodeExistOnRange(const FVector& location, float distance);
	const int32 GenerateObjectID() const;
};
