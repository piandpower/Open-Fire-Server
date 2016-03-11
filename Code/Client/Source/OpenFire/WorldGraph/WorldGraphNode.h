// Free to use

#pragma once

class ObjectData;

enum class WorldGraphNodeType
{
	None,
	Grass,
	Stone,
	Desert
};

class OPENFIRE_API WorldGraphNode
{
public:
	int32 nodeID;
	FVector location;
	WorldGraphNodeType type;

private:
	TMap<int32, ObjectData*> objectDataMap;

public:
	WorldGraphNode(int32 id, FVector location, WorldGraphNodeType type)
	{
		this->nodeID = id;
		this->location = location;
		this->type = type;
	};

	TMap<int32, ObjectData*> GetObjects();
	void AddObject(int32 objectID, ObjectData* objectData);
	void RemoveObject(int32 objectID);
};
