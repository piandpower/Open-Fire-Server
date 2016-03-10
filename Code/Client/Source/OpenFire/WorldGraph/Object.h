// Free to use

#pragma once

class OPENFIRE_API Object
{
public:
	enum class Type
	{
		None,
		Building
	};

	int32 objectID = -1;
	int32 nodeID = -1;
	Type type = Type::None;

	Object(int32 objectID, int32 nodeID);
	void SetNodeID(int32 nodeID);

	void OnUpdate();
};
