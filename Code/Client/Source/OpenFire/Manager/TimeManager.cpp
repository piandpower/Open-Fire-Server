#include "OpenFire.h"
#include "TimeManager.h"

const float updateSeconds = 5.0f;

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
