//
// Created by Cyril Battistolo on 05/01/2023.
//

#include "light.hpp"

Light::Light(glm::vec3 position, glm::vec3 color, float intensity) :
	model("assets/light.obj"),
	color(color),
	intensity(intensity),
	specularStrength(0.5f),
	shininess(32.0f)
{
	// TODO: init light model
	model.position = position;
	model.scale = glm::vec3(0.1f);
	model.rotation = glm::vec3(-22.0f, 0.0f, 0.0f);
}

Light::Light() : Light(glm::vec3(0.0f, 2.0f, 10.0f), glm::vec3(1.0f), 1.0f)
{
}

void Light::draw(Shader &shader, Camera camera)
{
	model.draw(shader, camera);
}
