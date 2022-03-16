#pragma once
#include <vector>

#include <GLM/glm.hpp>

#include "Util/Event.h"

class GameObject {
	glm::vec3 position;
	glm::mat4 translation, rotation;
	glm::vec3 angles;

public:
	GameObject();
	virtual ~GameObject();

	Event<glm::vec3> onSetPosition, onSetRotation;

	void Translate(glm::vec3 translate);
	void Rotate(glm::vec3 rotation);

	void SetPosition(glm::vec3 position);
	void SetRotation(glm::vec3 eulerAngles, bool relative = false);

	glm::mat4 GetTranslationMatrix() const;
	glm::mat4 GetRotationMatrix() const;

	//the resultant matrix of both the rotation and translation matrix
	glm::mat4 GetTransformationMatrix() const;

	glm::vec3 GetForwardVector() const;
	glm::vec3 GetRightVector() const;
	glm::vec3 GetUpVector() const;

	glm::vec3 GetPosition() const;
};