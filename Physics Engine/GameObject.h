#pragma once
#include <vector>

#include <GLM/glm.hpp>

#include "Util/Event.h"

class GameObject {
	glm::vec3 position;
	glm::mat4 translation, rotation;

	float yaw, pitch;

	Event<glm::vec3> onSetPosition;
	Event<float, float> onSetRotation;

public:
	GameObject();

	void SetPosition(glm::vec3 position);

	void SetRotation(float yaw, float pitch);

};