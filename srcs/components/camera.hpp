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

	float FOV;
	glm::mat4 projection;

	Camera();
	Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up);
	glm::mat4 getView() const;
	float getSpeed() const;
	void update();

private:
	float baseSpeed = 5.0f;
};


#endif //CAMERA_HPP
