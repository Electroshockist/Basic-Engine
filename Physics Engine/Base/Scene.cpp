#include "Scene.h"

const bool Scene::OnCreate() {
	importer = new AssetImporter();
	return true;
}

const bool Scene::Render() const {
	return true;
}

const bool Scene::Update(unsigned int fps) {
	return true;
}
