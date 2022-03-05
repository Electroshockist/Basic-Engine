#pragma once
struct Timer{
	Timer(const Timer&) = delete;
	Timer(const Timer&&) = delete;
	Timer& operator= (const Timer&) = delete;
	Timer& operator= (Timer&&) = delete;

	Timer();
	~Timer();


	void Start();
	void UpdateFrameTicks();
	float GetDeltaTime() const;
	unsigned int GetSleepTime(const unsigned int fps) const;
	float GetCurrentTicks() const;

private:
	unsigned int prevTicks;
	unsigned int currentTicks;
};

