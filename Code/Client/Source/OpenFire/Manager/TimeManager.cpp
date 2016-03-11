#include "OpenFire.h"
#include "TimeManager.h"

TimeManager* TimeManager::instance = nullptr;

const float updateSeconds = 5.0f;

TimeManager* TimeManager::Instance()
{
	if (instance == nullptr)
	{
		instance = new TimeManager();
	}

	return instance;
}

float TimeManager::GetRemainingSeconds()
{
	return updateSeconds - this->accumulatedSeconds;
}

void TimeManager::AddSeconds(float deltaSeconds)
{
	this->accumulatedSeconds += deltaSeconds;
}

void TimeManager::RewindSeconds()
{
	this->accumulatedSeconds -= updateSeconds;
}
