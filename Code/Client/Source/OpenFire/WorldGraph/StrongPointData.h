// Free to use

#pragma once

class ObjectData;
class BuildingData;
class ResourceData;

class OPENFIRE_API StrongPointData
{
public:
	int32 nodeID;
	FVector location;

private:
	BuildingData* buildingData = nullptr;
	TArray<ObjectData*> objectDatas;
	TArray<ResourceData*> resourceDatas;

public:
	StrongPointData(int32 id, FVector location)
	{
		this->nodeID = id;
		this->location = location;
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
