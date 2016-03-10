#pragma once

struct ObjectData;

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
		TArray<ObjectData*> objectDatas;
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

	TArray<Node*> Nodes;
	TArray<Edge*> Edges;

private:
	WorldGraph() {};
	WorldGraph(WorldGraph const&) {};
	WorldGraph& operator= (WorldGraph const&) { return *this; };

public:
	static WorldGraph* Instance();

	void OnUpdate();

	void AddNode(int32 Id, FVector Location);
	void AddEdge(int32 StartNodeId, int32 EndNodeId);

	const FVector GetEdgeLocation(const WorldGraph::Edge* edge);

	const TArray<WorldGraph::Node*> GetNodes();
	const TArray<WorldGraph::Edge*> GetEdges();

	void GenerateTestData();

	void SpawnBuilding(int32 nodeID, UWorld* world);

private:
	Node* GetNodeByID(int32 id);

	const FVector GetRandomNodeLocation();
	bool NodeExistOnRange(const FVector& location, float distance);
};
