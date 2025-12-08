#pragma once
#include <glm/glm.hpp>
#include <memory>

struct ray_t
{
	glm::vec3 origin;
	glm::vec3 direction;

	ray_t() = default;
	ray_t(glm::vec3 origin, glm::vec3 direction) {
		this->origin = origin;
		this->direction = direction;
	}


	glm::vec3 at(float t) const {
		return origin + t * direction;
	}

	glm::vec3 operator * (float t) {
		return at(t);
	}
};

struct raycastHit_t
{
	glm::vec3 point;      // point of intersection
	glm::vec3 normal;     // surface normal at intersection
	float distance{ 0 };  // distance from ray origin to intersection point
	class Material* material;
};