#include "Scene.h"

const bool Scene::OnCreate() {
	return true;
}

const bool Scene::Render() const {
	return true;
}

const bool Scene::Update(unsigned int fps) {
	return true;
}

Camera* const Scene::GetRenderingCamera() {
	return renderingCamera;
}
