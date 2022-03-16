#pragma once
#include "../../GameObject.h"

#include <memory>
#include <vector>

#include "../Geometry/Frustum.h"

class Model;

class Camera : public GameObject {
	float fieldOfView, nearPlane, farPlane;

	glm::mat4 perspective, orthographic;

	Frustum frustum;

	std::vector<Model*> models;

public:
	Camera();
	~Camera();

	const glm::mat4 GetPerspective();
	const glm::mat4 GetOrthographic();

	glm::vec2 GetClippingPlanes() const;

	Frustum GetFrustum() const;

	void AddModel(Model& model);

	void RemoveModel(Model& const model);

	void Render();
};

