// Free to use

#pragma once

enum class ObjectDataType
{
	None,
	Building,
	Unit
};

class OPENFIRE_API ObjectData
{
public:
	int32 objectID = -1;
	int32 nodeID = -1;
	ObjectDataType type = ObjectDataType::None;

public:
	void Initialize(int32 objectID, int32 nodeID);
	void SetNodeID(int32 nodeID);

	virtual void OnUpdate();
};
