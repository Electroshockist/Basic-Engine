#pragma once
#include "../3D/Camera/Camera.h"
#include "../3D/Model.h"
struct Scene {
	Scene() {}
	~Scene() {}
	const bool OnCreate();
	const bool Render() const;
	const bool Update(unsigned int fps);

private:
	Camera camera;
	Model* model;
};

