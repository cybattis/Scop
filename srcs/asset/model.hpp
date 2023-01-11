//
// Created by Cyril Battistolo on 26/12/2022.
//

#ifndef MODEL_HPP
#define MODEL_HPP

#include <iostream>
#include <vector>
#include "glad/glad.h"

#include "parser.hpp"
#include "mesh.hpp"

class Model
{
public:
	Model() = default;
	explicit Model(const std::string& path);
	Model(const Model &model) = default;
	Model &operator=(const Model &model) = default;

	void draw(Shader &shader, Camera camera);

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	glm::vec3 baseColor;

private:
	std::vector<Mesh> meshes;
	std::string directory;

	void load_model(const std::string &path);

};


#endif //MODEL_HPP
