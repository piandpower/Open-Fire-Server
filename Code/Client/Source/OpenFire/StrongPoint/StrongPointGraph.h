#pragma once

class OPENFIRE_API StrongPointGraph
{
public:
	struct Node
	{
		Node(int32 Id, FVector Location)
		{
			this->Id = Id;
			this->Location = Location;
		};

		int32 Id;
		FVector Location;
	};

	struct Edge
	{
		Edge(int32 Id, int32 StartNodeId, int32 EndNodeId)
		{
			this->StartNodeId = StartNodeId;
			this->EndNodeId = EndNodeId;
		};

		int32 Id;
		int32 StartNodeId;
		int32 EndNodeId;
	};

private:
	TArray<Node> Nodes;
	TArray<Edge> Edges;

public:
	StrongPointGraph();
	~StrongPointGraph();

	void AddNode(int32 Id, FVector Location);
	void AddEdge(int32 Id, int32 StartNodeId, int32 EndNodeId);

	const TArray<StrongPointGraph::Node>& GetNodes();

	void GenerateTestData();
};
