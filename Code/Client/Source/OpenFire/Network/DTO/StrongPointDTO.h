// Free to use

#pragma once

class StrongPointDTO
{
public:
	struct Data
	{
		int32 strongPointID;
		FString name;
		float positionX;
		float positionY;
	};

	TArray<Data> datas;

public:
	StrongPointDTO(const FString& string);
};