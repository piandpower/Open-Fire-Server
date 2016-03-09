#pragma once

class OPENFIRE_API StrongPointGraph
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
	TArray<Node*> Nodes;
	TArray<Edge*> Edges;

public:
	StrongPointGraph();
	~StrongPointGraph();

	void AddNode(int32 Id, FVector Location);
	void AddEdge(int32 StartNodeId, int32 EndNodeId);

	const FVector GetEdgeLocation(const StrongPointGraph::Edge* edge) const;

	const TArray<StrongPointGraph::Node*> GetNodes();
	const TArray<StrongPointGraph::Edge*> GetEdges();

	void GenerateTestData();

private:
	const Node* GetNodeByID(int32 id) const;

	const FVector GetRandomNodeLocation();
	bool NodeExistOnRange(const FVector& location, float distance);
};
