#include "Timer.h"

#include "SDL/SDL.h"

Timer::Timer() : prevTicks(0), currentTicks(0) {}

Timer::~Timer() {}

void Timer::Start() {
    prevTicks = SDL_GetTicks();
    currentTicks = SDL_GetTicks();
}

void Timer::UpdateFrameTicks() {
    prevTicks = currentTicks;
    currentTicks = SDL_GetTicks();
}

float Timer::GetDeltaTime() const {
    return static_cast<float>(currentTicks - prevTicks) / 1000.0f;
}

unsigned int Timer::GetSleepTime(const unsigned int fps) const {
	unsigned int milliPerFrame = 1000 / fps;
	if(milliPerFrame == 0) {
		return 0;
	}
	unsigned int sleepTime = milliPerFrame - (SDL_GetTicks());
	if(sleepTime > milliPerFrame) {
		return milliPerFrame;
	}
	return sleepTime;
}

float Timer::GetCurrentTicks() const {
	return static_cast<float>(currentTicks);
}
