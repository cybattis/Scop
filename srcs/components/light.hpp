//
// Created by Cyril Battistolo on 05/01/2023.
//

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "glad/glad.h"
#include "glm/vec3.hpp"

#include "../asset/model.hpp"

class Light
{
public:
	Model model;
	glm::vec3 color;
	float intensity;

	Light();
	Light(glm::vec3 position, glm::vec3 color, float intensity);

	void draw(Shader &shader, Camera camera);
};


#endif //LIGHT_HPP
