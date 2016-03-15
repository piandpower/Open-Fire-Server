// Free to use

#include "OpenFire.h"
#include "WorldGraphNode.h"
#include "WorldGraph/ObjectData/ObjectData.h"

const FVector objectLocationOffset = FVector(-200.0f, 0.0f, 0.0f);
const float objectLocationInterval = 200.0f;

void WorldGraphNode::SetBuilding(BuildingData* buildingData)
{
	this->buildingData = buildingData;
}

void WorldGraphNode::RemoveBuilding()
{
	this->buildingData = nullptr;
}

void WorldGraphNode::AddObject(ObjectData* objectData)
{
	this->objectDatas.Add(objectData);
}

void WorldGraphNode::RemoveObject(int32 objectID)
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

const FVector WorldGraphNode::GetObjectLocation(int32 objectID)
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

bool WorldGraphNode::HasBuilding()
{
	if (this->buildingData != nullptr)
	{
		return true;
	}

	return false;
}

const FVector WorldGraphNode::CalcObjectLocation(int32 index, int32 maxNum)
{
	FVector objectLocation = this->location + objectLocationOffset;

	float yInterval = (-0.5f * objectLocationInterval * float(maxNum - 1)) + (objectLocationInterval * float(index));

	objectLocation += FVector(0.0f, yInterval, 0.0f);

	return objectLocation;
}
