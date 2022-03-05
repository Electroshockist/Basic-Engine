#pragma once
#include <string>

#include "SDL/SDL.h"
#include "GLEW/glew.h"
#include "GLM/glm.hpp"

#include "Scene.h"

using namespace std;
struct Window {
	GLbitfield flags, clearflags;
	glm::vec4 clearColour;

	Window();

	bool OnCreate(string title, int x, int y, int width, int height, glm::vec4 clearColour = glm::vec4(0.1f, 0.01f, 0.0f, 1.0f), GLbitfield flags = 0, GLbitfield clearFlags = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Title
	void SetTitle(const string t);
	const string& GetTitle() const;

	//Position
	///position can only be set initially, therefore there are no setters for position

	//get window position
	glm::vec2 GetPosition() const;

	//get window X postition
	const int& GetX() const;
	//get window Y postition
	const int& GetY() const;

	//Size
	///Size can only be set initially, therefore there are no setters for size

	//get window size
	glm::vec2 getDimensions() const;

	//get window hight
	const int& GetWidth() const;
	//get window width
	const int& GetHeight() const;

	const bool Render(const Scene scene) const;

	SDL_Window* GetWindow() const;

	~Window() {};

private:
	string title;
	int x, y, width, height;

	SDL_Window* window;
	SDL_GLContext context;

	bool InitSDL();
	bool InitGL();
	void SetAttributes(int major, int minor);

	void GetInstalledOpenGLInfo(int* major, int* minor);
};

