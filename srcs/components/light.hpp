//
// Created by Cyril Battistolo on 05/01/2023.
//

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "glad/glad.h"
#include "glm/vec3.hpp"

#include "../asset/model.hpp"

enum LightType
{
	DIRECTIONAL,
	POINT,
	SPOT,
	AREA
};

class Light
{
public:
//	LightType type;   // 0: point, 1: directional, 2: spot, 3: area
	Model     model;  // TODO: hardcode light model
	glm::vec3 color;
	float     intensity;
	float     specularStrength;
	int       shininess;

	Light();
	Light(glm::vec3 position, glm::vec3 color, float intensity);
	Light(const Light& other) = default;
	Light& operator=(const Light& other) = default;

	void draw(Shader &shader, Camera camera);
};


#endif //LIGHT_HPP
