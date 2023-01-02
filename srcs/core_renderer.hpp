//
// Created by Cyril Battistolo on 21/12/2022.
//

#ifndef CORE_RENDERER_HPP
#define CORE_RENDERER_HPP

#include "glm/vec4.hpp"

#include "shader.hpp"
#include "asset/model.hpp"
#include "texture.hpp"
#include "asset/parser.hpp"
#include "components/camera.hpp"

class renderer
{
public:
	glm::vec4 clearColor;
	Camera camera;
	Shader activeShader{};
	Model obj;

	Shader gridShader{}; // TODO: make grid in shader
	GLuint grid_VAO{};
	indexArray grid_indices;

	renderer();

	void render();
	void computeObjects();

private:
	void drawGrid() const;
	void generateGrid(int size);
};


#endif //CORE_RENDERER_HPPP
