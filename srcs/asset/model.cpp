//
// Created by Cyril Battistolo on 26/12/2022.
//

#include "model.hpp"

Model::Model(const std::string &path)
{
	load_model(path);
}

void Model::load_model(const std::string &path)
{
	Parser::dataMesh* data = Parser::parse_file(path);
	VertexArray vertices;
	IndexArray indices;
	TextureArray textures;

	textures.emplace_back("assets/textures/container.jpg", "diffuse");
	textures.emplace_back("assets/textures/awesomeface.png", "diffuse");

	for (int i = 0; i < data->v_Position.size(); i++)
	{
		Vertex vertex{};
		vertex.position = data->v_Position[i];

		if (!data->v_Color.empty())
			vertex.color = data->v_Color[i];
		else
			vertex.color = glm::vec3(0.0f, 0.0f, 0.0f);

		if (!data->v_Normal.empty())
			vertex.normal = data->v_Normal[i];
		else
			vertex.normal = glm::vec3(0.0f, 0.0f, 0.0f);

		if (!data->v_TexCoord.empty())
			vertex.texCoords = data->v_TexCoord[i];
		else
			vertex.texCoords = glm::vec2(0.0f, 0.0f);

		vertices.push_back(vertex);
	}
	for (int i = 0; i < data->indices.size(); i++)
		indices.push_back(data->indices[i]);
	meshes.emplace_back(vertices, indices, textures);
}

void Model::Draw(Shader &shader)
{
	for (unsigned int i = 0; i < meshes.size(); i++)
		meshes[i].draw(shader);
}
