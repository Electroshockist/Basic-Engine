#include "Window.h"

#include <iostream>

#include "Glm/gtx/string_cast.hpp"

Window* Window::activeWindow = nullptr;

Window::Window() : title(""), x(0), y(0), width(0), height(0), window(nullptr), context(nullptr), clearflags(0), flags(0), clearColour(0) {
	activeWindow = this;
}

bool Window::OnCreate(string title, int x, int y, int width, int height, glm::vec4 clearColour, GLbitfield flags, GLbitfield clearFlags) {
	this->title = title;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->clearColour = clearColour;
	this->clearflags = clearFlags;
	this->flags = flags;

	activeWindow = this;

	if(!InitSDL()) return false;

	window = SDL_CreateWindow(title.c_str(), x, y, width, height, SDL_WINDOW_OPENGL);

	if(window == nullptr) {
		return false;
	}

	if(!InitGL()) return false;

	return true;
}

void Window::SetTitle(const string t) {
	title = t;
	SDL_SetWindowTitle(window, t.c_str());
}

const string& Window::GetTitle() const {
	return title;
}

glm::vec2 Window::GetPosition() const {
	return glm::vec2(GetX(), GetY());
}
inline const int& Window::GetX() const {
	return x;
}

const int& Window::GetY() const {
	return y;
}

glm::vec2 Window::GetDimensions() const {
	return glm::vec2(GetWidth(), GetHeight());
}

const int& Window::GetWidth() const {
	return width;
}

const int& Window::GetHeight() const {
	return height;
}

const bool Window::Render(const Scene scene) const {
	glClearColor(clearColour.x,clearColour.y, clearColour.z, clearColour.w);
	glClear(clearflags);
	bool returnVal = scene.Render();
	SDL_GL_SwapWindow(window);
	return returnVal;
}

SDL_Window* const Window::GetWindow() const {
	return window;
}

Window* const Window::GetActiveWindow() {
	return activeWindow;
}

bool Window::InitSDL() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
		return false;
	}
	return true;
}

bool Window::InitGL() {
	context = SDL_GL_CreateContext(window);

	int major, minor;
	GetInstalledOpenGLInfo(&major, &minor);
	SetAttributes(major, minor);

	/// Fire up the GL Extension Wrangler
	GLenum err = glewInit();
	if(err != GLEW_OK) {
		return false;
	}

	glEnable(GL_DEPTH_TEST);

	glViewport(0, 0, GetWidth(), GetHeight());
	return true;
}

void Window::SetAttributes(int major, int minor) {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
	SDL_GL_SetSwapInterval(1);
	glewExperimental = GL_TRUE;
}

void Window::GetInstalledOpenGLInfo(int* major, int* minor) {
	/// You can to get some info regarding versions and manufacturer
	const GLubyte* version = glGetString(GL_VERSION);
	const GLubyte* glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
	/// You can also get the version as ints	
	const GLubyte* vendor = glGetString(GL_VENDOR);
	const GLubyte* renderer = glGetString(GL_RENDERER);

	std::cout << "GL Version " << version << std::endl;
	std::cout << "GLSL Version " << glslVersion << std::endl;
	std::cout << "Graphics card vendor " << vendor << std::endl;
	std::cout << "Graphics card name " << renderer << std::endl;
	glGetIntegerv(GL_MAJOR_VERSION, major);
	glGetIntegerv(GL_MINOR_VERSION, minor);

	std::cout << std::endl;

	return;
}
