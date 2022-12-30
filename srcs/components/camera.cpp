//
// Created by Cyril Battistolo on 29/12/2022.
//

#include "camera.hpp"

Camera::Camera() :
	position(glm::vec3(0.0f, 3.0f, 20.0f)),
	front(glm::vec3(0.0f, 0.0f, -1.0f)),
	up(glm::vec3(0.0f, 1.0f, 0.0f))
{

}


Camera::Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up) :
	position(position), front(front), up(up)
{
}

glm::mat4 Camera::getView()
{
	return glm::lookAt(position, position + front, up);
}

float Camera::getSpeed()
{
	return baseSpeed * deltaTime;
}
