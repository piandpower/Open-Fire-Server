#pragma once

class OPENFIRE_API TimeManager
{
private:
	static TimeManager* instance;

	float accumulatedSeconds = 0.0f;

private:
	TimeManager() {};
	TimeManager(TimeManager const&) {};
	TimeManager& operator= (TimeManager const&) { return *this; };

public:
	static TimeManager* Instance();

	float GetRemainingSeconds();

	void AddSeconds(float deltaSeconds);

	void RewindSeconds();
};
