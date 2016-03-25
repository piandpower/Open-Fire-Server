// Free to use

#include "OpenFire.h"
#include "StrongPointData.h"
#include "WorldGraph/ObjectData/ObjectData.h"
#include "WorldGraph/ObjectData/Resource/ResourceData.h"

const FVector objectLocationOffset = FVector(-200.0f, 0.0f, 0.0f);
const float objectLocationInterval = 200.0f;

void StrongPointData::SetBuilding(BuildingData* buildingData)
{
	this->buildingData = buildingData;
}

void StrongPointData::RemoveBuilding()
{
	this->buildingData = nullptr;
}

void StrongPointData::AddObject(ObjectData* objectData)
{
	this->objectDatas.Add(objectData);
}

void StrongPointData::RemoveObject(int32 objectID)
{
	for (ObjectData* objectData : this->objectDatas)
	{
		if (objectData->objectID == objectID)
		{
			this->objectDatas.Remove(objectData);
			break;
		}
	}
}

void StrongPointData::AddResource(ResourceData* resourceData)
{
	this->resourceDatas.Add(resourceData);
}

void StrongPointData::RemoveResource(int32 objectID)
{
	for (ResourceData* resourceData : this->resourceDatas)
	{
		if (resourceData->objectID == objectID)
		{
			this->resourceDatas.Remove(resourceData);
			break;
		}
	}
}

const FVector StrongPointData::GetObjectLocation(int32 objectID)
{
	for (int32 i = 0; i != this->objectDatas.Num(); ++i)
	{
		if (this->objectDatas[i]->objectID == objectID)
		{
			return this->CalcObjectLocation(i, this->objectDatas.Num());
		}
	}

	return FVector::ZeroVector;
}

const FVector StrongPointData::GetResourceLocation(int32 objectID)
{
	return this->location + objectLocationOffset;
}

bool StrongPointData::HasBuilding()
{
	if (this->buildingData != nullptr)
	{
		return true;
	}

	return false;
}

const FVector StrongPointData::CalcObjectLocation(int32 index, int32 maxNum)
{
	FVector objectLocation = this->location + objectLocationOffset;

	float yInterval = (-0.5f * objectLocationInterval * float(maxNum - 1)) + (objectLocationInterval * float(index));

	objectLocation += FVector(0.0f, yInterval, 0.0f);

	return objectLocation;
}
