#pragma once

#include "Framework/Singleton.h"

class AStrongPoint;
class AGameObject;
enum class ObjectDataType;

class OPENFIRE_API GameObjectManager : public Singleton<GameObjectManager>
{
private:
	UWorld* world = nullptr;

	TMap<int32, AStrongPoint*> strongPointMap;
	TMap<int32, AGameObject*> gameObjectMap;

public:
	void Initialize(UWorld* world);

	void OnUpdate();

private:
	void SpawnStrongPoint(int32 nodeID, FVector location);
	void SpawnObject(int32 objectID, int32 strongPointID, ObjectDataType type);

	void UpdateStrongPoints();
	void UpdateGameObjects();
};
