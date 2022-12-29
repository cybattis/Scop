//
// Created by Cyril Battistolo on 21/12/2022.
//

#ifndef CORE_RENDERER_HPP
#define CORE_RENDERER_HPP

#include "core.hpp"
#include "shader.hpp"
#include "asset/model.hpp"
#include "texture.hpp"
#include "asset/parser.hpp"

#include "cube_textured.hpp"

class renderer
{
public:
	Model obj;
	Shader texture_shader{};
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	renderer();

	void render();
	void compute_objects();
};


#endif //CORE_RENDERER_HPP
