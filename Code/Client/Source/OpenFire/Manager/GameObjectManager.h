#pragma once

#include "Framework/Singleton.h"

class AStrongPoint;
class AGameObject;

class OPENFIRE_API GameObjectManager : public Singleton<GameObjectManager>
{
private:
	UWorld* world = nullptr;

	TMap<int32, AStrongPoint*> strongPointMap;
	TArray<AGameObject*> gameObjects;

public:
	void Initialize(UWorld* world);

	void OnUpdate();

private:
	void SpawnStrongPoint(int32 nodeID, FVector location);

	void UpdateStrongPoints();
};
