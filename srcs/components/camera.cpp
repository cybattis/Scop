//
// Created by Cyril Battistolo on 29/12/2022.
//

#include "camera.hpp"

Camera::Camera() : Camera(glm::vec3(0.0f, 3.0f, 20.0f),
		                  glm::vec3(0.0f, 0.0f, -1.0f),
		                  glm::vec3(0.0f, 1.0f, 0.0f))
{
	projection = glm::perspective(glm::radians(FOV), 1440.0f / 960.0f, nearPlane, farPlane);
}


Camera::Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up, float FOV) :
	position(position), front(front), up(up), FOV(FOV)
{
}

glm::mat4 Camera::getView() const
{
	return glm::lookAt(position, position + front, up);
}

float Camera::getSpeed() const
{
	return baseSpeed * deltaTime;
}

void Camera::update()
{
	projection = glm::perspective(glm::radians(FOV), aspectRatio, 1.0f, 100.0f);
}
