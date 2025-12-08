#pragma once
#include "Ray.h"
#include "Color.h"
#include "Transform.h"
#include "Material.h"

class Object
{
public:
	Object() = default;
	Object(const Transform& transform, std::shared_ptr<Material> material) :
		transform{ transform },
		material{ material }
	{
	}
	virtual bool Hit(const ray_t& ray, float minDistance, float maxDistance, raycastHit_t& raycastHit) const = 0;

	Transform transform;
	std::shared_ptr<Material> material;
};