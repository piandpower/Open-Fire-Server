// Free to use

#pragma once

class ObjectData;

class OPENFIRE_API WorldGraphNode
{
public:
	int32 nodeID;
	FVector location;

private:
	TMap<int32, ObjectData*> objectDataMap;

public:
	WorldGraphNode(int32 id, FVector location)
	{
		this->nodeID = id;
		this->location = location;
	};

	TMap<int32, ObjectData*> GetObjects();
	void AddObject(int32 objectID, ObjectData* objectData);
	void RemoveObject(int32 objectID);
};
