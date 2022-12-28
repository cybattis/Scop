//
// Created by Cyril Battistolo on 26/12/2022.
//

#ifndef MODEL_HPP
#define MODEL_HPP

#include <iostream>
#include <vector>

#include "glad/glad.h"

#include "../texture.hpp"
#include "parser.hpp"
#include "mesh.hpp"


class Model
{
	typedef std::vector<Vertex>  VertexArray;
	typedef std::vector<GLuint>  IndexArray;
	typedef std::vector<Texture> TextureArray;

public:
	Model() = default;
	Model(const std::string& path);
	void Draw(Shader &shader);

private:
	std::vector<Mesh> meshes;
	std::string directory;

	void load_model(const std::string &path);

};


#endif //MODEL_HPP
