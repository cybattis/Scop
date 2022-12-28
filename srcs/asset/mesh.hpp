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

struct Vertex {
	glm::vec3 position;
	glm::vec3 color;
	glm::vec3 normal;
	glm::vec2 texCoords;
};

class Mesh
{
	typedef std::vector<Vertex>  VertexArray;
	typedef std::vector<GLuint>  IndexArray;
	typedef std::vector<Texture> TextureArray;

public:
	// mesh data
	VertexArray  vertices;
	IndexArray   indices;
	TextureArray textures;
	GLuint       VAO, SSBO;

	Mesh() = default;
	Mesh(VertexArray& vertices, IndexArray& indices, TextureArray& textures);
	void draw(Shader &shader);

private:
	GLuint VBO{}, EBO{};
	void setupMesh();
};


#endif //MESH_HPP
