#include "GameObject.h"

#include <GLM/gtx/euler_angles.hpp>
#include <GLM/gtc/matrix_transform.hpp>

GameObject::~GameObject() {
}

void GameObject::Translate(glm::vec3 translate) {
	//todo allow relative translation
	position += translate;
	glm::translate(translation, translate);

	onSetPosition.Invoke(this->position);
}

void GameObject::Rotate(glm::vec3 rotation) {
	//todo allow relative rotation
	angles += rotation;
	this->rotation = glm::rotate(this->rotation, rotation.x, glm::vec3(1,0,0));
	this->rotation = glm::rotate(this->rotation, rotation.y, glm::vec3(0,1,0));
	this->rotation = glm::rotate(this->rotation, rotation.z, glm::vec3(0,0,1));

}

void GameObject::SetPosition(glm::vec3 position) {
	this->position = position;

	translation = glm::translate(glm::mat4(1), position);

	onSetPosition.Invoke(position);
}

void GameObject::SetRotation(glm::vec3 rotation, bool relative) {
	angles = rotation;

	this->rotation = glm::eulerAngleXYZ(angles.x, angles.y, angles.z);

	onSetRotation.Invoke(angles);
}

glm::vec3 GameObject::GetForwardVector() const {
	const glm::mat4 inverted = glm::inverse(GetTransformationMatrix());
	return normalize(glm::vec3(inverted[2]));
}

//to implement
glm::vec3 GameObject::GetRightVector() const {
	return glm::vec3();
}

//to implement
glm::vec3 GameObject::GetUpVector() const {
	return glm::vec3();
}

glm::mat4 GameObject::GetTranslationMatrix() const {
	return translation;
}

glm::mat4 GameObject::GetRotationMatrix() const {
	return rotation;
}

glm::mat4 GameObject::GetTransformationMatrix() const {
	return GetRotationMatrix() * GetTranslationMatrix();
}

glm::vec3 GameObject::GetPosition() const {
	return position;
}
