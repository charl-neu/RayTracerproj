#pragma once
#include "Object.h"
class Sphere : public Object
{
public:
	Sphere() = default;
	Sphere(const glm::vec3& position, float radius, const color3_t& color) :
		position{ position }
	{
		this->radius = radius;
		this->color = color;
	}

	bool Hit(const ray_t& ray, float minDistance, float maxDistance, raycastHit_t& raycastHit) const override;
public:
	glm::vec3 position;
	float radius{ 0 };
};