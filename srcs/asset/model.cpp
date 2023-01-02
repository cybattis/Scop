//
// Created by Cyril Battistolo on 26/12/2022.
//

#include "model.hpp"

Model::Model(const std::string &path) :
	position{0.0f, 0.0f, 0.0f},
	rotation{0.0f, 0.0f, 0.0f},
	scale{1.0f, 1.0f, 1.0f}
{
	load_model(path);
}

void Model::load_model(const std::string &path)
{
	dataMeshes mesh = Parser::parse_file(path);
	// TODO put texture array in dataMesh
	textureArray textures;
	textures.emplace_back("assets/textures/container.jpg", "diffuse");
	textures.emplace_back("assets/textures/awesomeface.png", "diffuse");

	for (auto &m : mesh)
		meshes.emplace_back(m, textures);
}

void Model::draw(Shader &shader, Camera camera)
{
	shader.use(camera);

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(position[0], position[1], position[2]));
	model = glm::rotate(model, glm::radians(rotation[0]), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::radians(rotation[1]), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, glm::radians(rotation[2]), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(scale[0], scale[0], scale[0]));
	shader.setMat4("model", model);

	for (auto & meshe : meshes)
		meshe.draw(shader);
}
