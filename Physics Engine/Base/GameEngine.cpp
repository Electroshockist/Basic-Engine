#include "GameEngine.h"

#include "GLEW/glew.h"

std::unique_ptr<GameEngine> GameEngine::instance = nullptr;

GameEngine::GameEngine() : isRunning(false), fps(120), scene(new Scene()) {}

GameEngine::~GameEngine() {
	Exit();
	exit(0);
}

GameEngine* GameEngine::GetInstance() {
	if(!instance) {
		instance.reset(new GameEngine());
	}
    return instance.get();
}

bool GameEngine::OnCreate(int argc, char* argv[]) {
	if(!w.OnCreate("Test", 200, 200, 1080, 720)) {		
		return false;
	}

	timer.Start();

	return isRunning = true;
}

bool GameEngine::Run() {
	while(isRunning) {
		timer.UpdateFrameTicks();

		//if update or render returns error, return false
		if(!Update(timer.GetDeltaTime()) || !Render()) {
			return false;
		}

		SDL_Delay(timer.GetSleepTime(fps));
	}
	return true;
}

bool GameEngine::Update(const float deltaTime) {
	return true;
}

bool GameEngine::Render() {
	return w.Render(*scene);
}

void GameEngine::Exit() {
	isRunning = false;
}

void GameEngine::SetScene(Scene* scene) {
	this->scene = scene;
}
