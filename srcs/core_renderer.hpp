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
	Model obj;
	Shader activeShader{};
	glm::vec4 clear_color;
	Camera cam;

	renderer();

	void render();
	void computeObjects();
};


#endif //CORE_RENDERER_HPP
