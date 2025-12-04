#pragma once
#include "Ray.h"
#include "Color.h"
#include "Transform.h"

class Object
{
public:
	Object() = default;
	Object(const color3_t& color) : color{ color } {}

	virtual bool Hit(const ray_t& ray, float minDistance, float maxDistance, raycastHit_t& raycastHit) const = 0;

	Transform transform;
	color3_t color{ 1, 0, 1 }; // default magenta color
};