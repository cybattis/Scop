//
// Created by Cyril Battistolo on 29/12/2022.
//

#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"

struct vertex {
	glm::vec3 position;
	glm::vec3 color;
	glm::vec3 normal;
	glm::vec2 texCoords;
};

typedef std::vector<vertex> vertexArray;
typedef std::vector<GLuint> indexArray;

struct dataMesh {
	std::string  name;
	std::string  path;

	vertexArray vertices;
	indexArray  indices;
};

#endif //VERTEX_HPP
