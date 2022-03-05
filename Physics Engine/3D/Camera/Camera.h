#pragma once
#include "../../GameObject.h"
#include "../Geometry/Frustum.h"

class Camera : public GameObject {
	Camera();

	float fieldOfView, nearPlane, farPlane;

	Frustum frustum;
};

