#include "Camera.h"

#include <algorithm>

#include "../Model.h"

Camera::Camera() : perspective(glm::mat4(1)), orthographic(glm::mat4(1)), fieldOfView(45.0f), nearPlane(0.5f), farPlane(50.0f){
}

Camera::~Camera() {
}

const glm::mat4 Camera::GetPerspective() {
	return perspective;
}

const glm::mat4 Camera::GetOrthographic() {
	return orthographic;
}

glm::vec2 Camera::GetClippingPlanes() const {
	return glm::vec2(nearPlane, farPlane);
}

Frustum Camera::GetFrustum() const {
	return frustum;
}

void Camera::AddModel(Model& model) {
	models.push_back(&model);
}

void Camera::RemoveModel(Model& model) {
	models.erase(std::remove(models.begin(), models.end(), &model), models.end());
}

void Camera::Render() {
	//for(auto& model : models) {
	//	model->Render(this);
	//}
}
