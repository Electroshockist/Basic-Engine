#pragma once
#include <memory>

#include "Window.h"
#include "Scene.h"
#include "Timer.h"

struct GameEngine {
	//delete constructors for singleton
	GameEngine(const GameEngine&) = delete;
	GameEngine(GameEngine&&) = delete;
	GameEngine& operator=(const GameEngine&) = delete;
	GameEngine& operator=(GameEngine&&) = delete;

	static GameEngine* GetInstance();

	bool OnCreate(int argc, char* argv[]);

	bool Run();

	bool Update(const float deltaTime);
	bool Render();

	void Exit();

	void SetScene(Scene* scene);

private:
	GameEngine();
	~GameEngine();

	static std::unique_ptr<GameEngine> instance;
	friend std::default_delete<GameEngine>;

	bool isRunning;
	unsigned int fps;

	Timer timer;

	Window w;

	Scene* scene;
};