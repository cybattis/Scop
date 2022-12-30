//
// Created by Cyril Battistolo on 29/12/2022.
//

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "../Global.hpp"

class Camera
{
public:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;


	Camera();
	Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up);
	glm::mat4 getView();
	float getSpeed();

private:
	float baseSpeed = 2.5f;
};


#endif //CAMERA_HPP
