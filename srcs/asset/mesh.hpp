//
// Created by Cyril Battistolo on 26/12/2022.
//

#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"

#include "../shader.hpp"
#include "../texture.hpp"
#include "vertex.hpp"

typedef std::vector<Texture> textureArray;

class Mesh
{
public:
	// mesh data
	dataMesh     data;
	textureArray textures;
	GLuint       VAO;

	Mesh() = default;
	Mesh(dataMesh data, textureArray& textures);
//	Mesh(const Mesh &mesh) = default;
//	Mesh &operator=(const Mesh &mesh) = default;

	void draw(Shader &shader);

private:
	GLuint VBO, EBO;
	void setupMesh();
};


#endif //MESH_HPP
