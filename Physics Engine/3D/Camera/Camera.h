#ifndef CAMERA_H
#define CAMERA_H

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

	static std::vector<std::unique_ptr<Camera>> cameras;

	Camera();

	Camera(glm::vec3 position, float fieldOfView, float nearPlane, float farPlane);
	
	~Camera();

public:
	friend std::default_delete<Camera>;
	static Camera* LoadCamera(glm::vec3 position, float fieldOfView, float nearPlane, float farPlane);

	const glm::mat4 GetPerspective();
	const glm::mat4 GetOrthographic();

	glm::vec2 GetClippingPlanes() const;

	Frustum GetFrustum() const;

	void AddModel(Model* model);

	void RemoveModel(Model* model);

	void Render();

	static const std::vector<std::unique_ptr<Camera>> GetCameras();
};

#endif // !CAMERA_H
