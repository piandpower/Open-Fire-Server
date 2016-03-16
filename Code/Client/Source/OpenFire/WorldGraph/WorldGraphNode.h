// Free to use

#pragma once

class ObjectData;
class BuildingData;
class ResourceData;

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
	BuildingData* buildingData = nullptr;
	TArray<ObjectData*> objectDatas;
	TArray<ResourceData*> resourceDatas;

public:
	WorldGraphNode(int32 id, FVector location, WorldGraphNodeType type)
	{
		this->nodeID = id;
		this->location = location;
		this->type = type;
	};

	void SetBuilding(BuildingData* buildingData);
	void RemoveBuilding();

	void AddObject(ObjectData* objectData);
	void RemoveObject(int32 objectID);

	void AddResource(ResourceData* resourceData);
	void RemoveResource(int32 objectID);

	const FVector GetObjectLocation(int32 objectID);
	const FVector GetResourceLocation(int32 objectID);

	bool HasBuilding();

private:
	const FVector CalcObjectLocation(int32 index, int32 maxNum);
};
