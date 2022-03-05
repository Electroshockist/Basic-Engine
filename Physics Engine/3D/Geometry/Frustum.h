#pragma once
#include <glm/glm.hpp>

class Frustum {
	glm::vec4 planes[6] = {};

	enum Halfspace {
		NEGATIVE = -1,
		ON_PLANE = 0,
		POSITIVE = 1
	};

	inline Halfspace classifyPoint(const glm::vec4& plane, const glm::vec3& point) {
		float d;
		d = plane.x * point.x + plane.y * point.y + plane.z * point.z + plane.w;
		if(d < 0) return NEGATIVE;
		if(d > 0) return POSITIVE;
		return ON_PLANE;
	}

	void updateMatrix(glm::mat4 projMatrix, glm::mat4 viewMatrix);

	inline void normalizePlane(glm::vec4& plane) {
		double magnitude = glm::sqrt(
			plane.x * plane.x +
			plane.y * plane.y +
			plane.z * plane.z
		);

		plane.x /= magnitude;
		plane.y /= magnitude;
		plane.z /= magnitude;
		plane.w /= magnitude;
	}

public:
	Frustum() {};
	~Frustum() {};

	enum PlaneName {
		Left,
		Right,
		Top,
		Bottom,
		Near,
		Far
	};

	bool isInView(const glm::vec3& point);
};