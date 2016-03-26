// Free to use

#pragma once

class StrongPointDTO
{
public:
	struct Data
	{
		int32 strongPointID = -1;
		FString name = "";
		FVector location = FVector::ZeroVector;
	};

public:
	TArray<Data> datas;

public:
	StrongPointDTO(const FString& string);
};