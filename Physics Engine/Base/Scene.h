#pragma once
#include "../3D/Camera/Camera.h"
#include "../3D/Model.h"

class Scene {
public:
	Scene() : model() {}
	~Scene() {}
	const bool OnCreate();
	const bool Render() const;
	const bool Update(unsigned int fps);

	Camera* const GetRenderingCamera();

private:
	Camera* renderingCamera;
	Model* model;
};

