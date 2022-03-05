#include "GameObject.h"

#include <GLM/gtx/euler_angles.hpp>

GameObject::GameObject() : position(glm::vec3(0)), translation(glm::mat4(0)), rotation(glm::mat4()), yaw(0.0f), pitch(0.0f) {}

void GameObject::SetPosition(glm::vec3 position) {
	this->position = position;

	translation = glm::translate(glm::mat4(1), position);

	onSetPosition.Invoke(position);
}

void GameObject::SetRotation(float yaw, float pitch) {
	this->yaw = yaw;
	this->pitch = pitch;
	rotation = glm::eulerAngleXYZ(pitch, yaw, 0.0f);

	onSetRotation.Invoke(pitch, yaw);
}
