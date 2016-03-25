// Free to use

#pragma once

#include "MissionValues.h"

enum class ObjectDataType
{
	None,

	//Building
	Building,	//DEPRECATED
	Castle,

	//Unit
	Unit,

	//Resource
	Resource
};

class OPENFIRE_API ObjectData
{
private:
	MissionValues missionValues;

public:
	int32 objectID = -1;
	int32 strongPointID = -1;

	ObjectDataType type = ObjectDataType::None;

public:
	void Initialize(int32 objectID, int32 strongPointID, ObjectDataType type);
	void SetNodeID(int32 strongPointID);

	void SetMissionValues(const MissionValues& missionValues);
	const FLinearColor GetMissionColor() const;

	virtual void OnUpdate();
};
