//
// Created by Cyril Battistolo on 26/12/2022.
//

#include "mesh.hpp"

#include <utility>

Mesh::Mesh(dataMesh data, textureArray& textures) :
	data(std::move(data)), textures(std::move(textures)), VAO(0), VBO(0), EBO(0)
{
	setupMesh();
}

void Mesh::setupMesh()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER,
				data.vertices.size() * sizeof(Vertex), &data.vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			static_cast<GLsizei>(data.indices.size() * sizeof(GLuint)), &data.indices[0], GL_STATIC_DRAW);

	// vertex positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
	// vertex colors
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	// vertex normals
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
	// vertex texture coords
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));

	glBindVertexArray(0);
	std::cout << "Mesh setup" << std::endl;
}


void Mesh::draw(Shader &shader)
{
	GLuint diffuseNr  = 1;
	GLuint specularNr = 1;
	GLuint normalNr   = 1;
	GLuint heightNr   = 1;

	GLuint number     = 0;

	for(unsigned int i = 0; i < textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);

		std::string type = textures[i].type;
		if(type == "diffuse")
			number = diffuseNr++;
		else if(type == "specular")
			number = specularNr++;
		else if(type == "normal")
			number = normalNr++;
		else if(type == "height")
			number = heightNr++;

		std::string name = "texture_" + type + std::to_string(number);
		// now set the sampler to the correct texture unit
		shader.setInt(name, static_cast<int>(i));
		// and finally bind the texture
		glBindTexture(GL_TEXTURE_2D, textures[i].id);
	}

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(data.indices.size()), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	// always good practice to set everything back to defaults once configured.
	glActiveTexture(GL_TEXTURE0);
}
