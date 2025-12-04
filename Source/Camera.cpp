#include "Camera.h"

void Camera::SetView(const glm::vec3& eye, const glm::vec3& target, const glm::vec3& up) {
	this->eye = eye;

	// create camera axis
	this->forward = glm::normalize(target - eye); //this points the foward vector towards the target location
	this->right = glm::normalize(glm::cross(forward, up));//this points the right vector to the right of the forward vector by using the up vector as a reference {1,0,0} cross {0,0,-1} = {0,1,0}
	this->up = glm::normalize(glm::cross(right, forward));//this points the up vector to the up of the forward vector by using the right vector as a reference {0,1,0} cross {0,0,-1} = {1,0,0}

	CalculateViewPlane();
}

ray_t Camera::GetRay(const glm::vec2& uv) const {
	ray_t ray;

	ray.origin = eye;
	ray.direction = glm::normalize(lowerLeft + uv.x * horizontal + uv.y * vertical - eye); //point from eye to the view location

	return ray;
}

void Camera::CalculateViewPlane() {
	float theta = glm::radians(fov); //convert fov to radians

	float halfHeight = tan(theta / 2.0f); //calculate the half height of the view plane using tan(fov/2)
	float halfWidth = aspectRatio * halfHeight; // calculate the half width of the view plane using the aspect ratio

	horizontal = 2.0f * halfWidth * right; //calculate the horizontal vector of the view plane by multiplying the right vector by the full width of the view plane
	vertical = 2.0f * halfHeight * up; //calculate the vertical vector of the view plane by multiplying the up vector by the full height of the view plane

	lowerLeft = eye - (horizontal * 0.5f) - (vertical * 0.5f) + forward; //calculate the lower left corner of the view plane, where the eye is the camera, foward is the forward direction of the camera, and half the horizontal and vertical vectors are subtracted to get to the lower left corner
}

