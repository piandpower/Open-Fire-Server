// Free to use

#include "OpenFire.h"
#include "ObjectData.h"
#include "WorldGraph/WorldGraph.h"
#include "WorldGraph/StrongPointData.h"

void ObjectData::Initialize(int32 objectID, int32 strongPointID, ObjectDataType type)
{
	this->objectID = objectID;
	this->strongPointID = strongPointID;
	this->type = type;
}

void ObjectData::SetNodeID(int32 strongPointID)
{
	this->strongPointID = strongPointID;
}

void ObjectData::SetMissionValues(const MissionValues& missionValues)
{
	this->missionValues = missionValues;
}

const FLinearColor ObjectData::GetMissionColor() const
{
	return this->missionValues.GetColor();
}

void ObjectData::OnUpdate()
{
}
