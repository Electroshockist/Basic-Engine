#include "Camera.h"

#include <algorithm>

#include <GLM/gtc/matrix_transform.hpp>

#include "../Model.h"
#include "../../Base/Window.h"

std::vector<std::unique_ptr<Camera>> Camera::cameras = std::vector<std::unique_ptr<Camera>>();

Camera::Camera() : perspective(glm::mat4(1)), orthographic(glm::mat4(1)), farPlane(0), fieldOfView(0), nearPlane(0) {
	SetPosition(glm::vec3(0));

	GetPerspective();
	GetOrthographic();
}

Camera::Camera(glm::vec3 position, float fieldOfView, float nearPlane, float farPlane)
	: perspective(glm::mat4(1)), orthographic(glm::mat4(1)), fieldOfView(fieldOfView), nearPlane(nearPlane), farPlane(farPlane) {
	
	SetPosition(position);

	GetPerspective();
	GetOrthographic();
}

Camera::~Camera() {
	for(size_t i = 0; i < cameras.size(); i++) {
		if(cameras[i].get() == this) {
			cameras.erase(cameras.begin() + i);
		}
	}
}

Camera* Camera::LoadCamera(glm::vec3 position, float fieldOfView, float nearPlane, float farPlane) {
	Camera* cam = new Camera();

	for(const auto& camera : cameras) {
		if(camera.get()->GetPosition() == position) {
			return camera.get();
		}
	}

	if(!cam) {
		cam = new Camera(position, fieldOfView, nearPlane, farPlane);
	}
	
	std::unique_ptr<Camera> camera = std::unique_ptr<Camera>(cam);
	
	return cam;
}

const glm::mat4 Camera::GetPerspective() {
	const glm::vec2& dimensions = Window::GetActiveWindow()->GetDimensions();
	perspective = glm::perspective(fieldOfView, dimensions.x/dimensions.y, nearPlane, farPlane);
	return perspective;
}

const glm::mat4 Camera::GetOrthographic() {
	const glm::vec2& dimensions = Window::GetActiveWindow()->GetDimensions();
	orthographic = glm::ortho(0.0f, dimensions.x, 0.0f, dimensions.y, nearPlane, farPlane);
	return orthographic;
}

glm::vec2 Camera::GetClippingPlanes() const {
	return glm::vec2(nearPlane, farPlane);
}

Frustum Camera::GetFrustum() const {
	return frustum;
}

void Camera::AddModel(Model * model) {
	model->onDeleted.Subscribe(RemoveModel);
	models.push_back(model);
}

void Camera::RemoveModel(Model* model) {
	models.erase(std::remove(models.begin(), models.end(), &model), models.end());
}

void Camera::Render() {
	for(const auto& model : models) {
		model->Render(this);
	}
}

const std::vector<std::unique_ptr<Camera>> Camera::GetCameras() {
	return cameras;
}
