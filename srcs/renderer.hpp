//
// Created by Cyril Battistolo on 21/12/2022.
//

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "glm/vec4.hpp"

#include "shader.hpp"
#include "asset/model.hpp"
#include "components/camera.hpp"
#include "components/light.hpp"

class renderer
{
public:
	glm::vec4 clearColor;
	Camera camera;

	Model obj; // TODO: make this a vector of models
	Light light;

	renderer();

	void render();
	void computeObjects();

private:
	Shader defaultShader{};
	Shader lightingShader{};

	// TODO: make grid in shader
	Shader gridShader{};
	GLuint grid_VAO{};
	indexArray grid_indices;

	void drawGrid() const;
	void generateGrid(int size);

	void setupLightingShader() const;
};


#endif //CORE_RENDERER_HPPP
