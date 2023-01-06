//
// Created by Cyril Battistolo on 05/01/2023.
//

#include "light.hpp"

Light::Light() :
	model("assets/light.obj"),
	color(glm::vec3(1.0f)),
	intensity(0.25f),
	specularStrength(0.5f),
	shininess(32.0f)
{
}

Light::Light(glm::vec3 position, glm::vec3 color, float intensity) :
	model("assets/light.obj"),
	color(color),
	intensity(intensity),
	specularStrength(0.5f),
	shininess(32.0f)
{
	model.scale = glm::vec3(0.1f);
	model.position = position;
}

void Light::draw(Shader &shader, Camera camera)
{
	model.draw(shader, camera);
}
