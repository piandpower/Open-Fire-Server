#pragma once

#include "Framework/Singleton.h"
#include "WorldGraph/StrongPointData.h"

class ObjectData;
class MissionValues;
enum class ObjectDataType;

class OPENFIRE_API WorldGraph : public Singleton<WorldGraph>
{
private:
	UWorld* world = nullptr;

	TArray<StrongPointData> strongPointDatas;
	TArray<ObjectData*> objectDatas;

public:
	void Initialize(UWorld* world);

	void OnUpdate();

	ObjectData* GetObject(int32 objectID);

	StrongPointData* GetNode(int32 nodeID);

	const TArray<StrongPointData>& GetStrongPointDatas();
	const TArray<ObjectData*> GetObjectDatas();

	void InsertUpdateStrongPointData(int32 id, FVector location);

	void AddObject(int32 objectID, int32 strongPointID, ObjectDataType type);
};
