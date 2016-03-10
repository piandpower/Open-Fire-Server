// Free to use

#pragma once

struct OPENFIRE_API Object
{
public:
	enum class Type
	{
		None,
		Building
	};

	int32 objectID = -1;
	Type type = Type::None;

	void OnUpdate();
};
