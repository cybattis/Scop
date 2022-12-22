//
// Created by Cyril Battistolo on 21/12/2022.
//

#ifndef CORE_RENDERER_HPP
#define CORE_RENDERER_HPP

#include "core.hpp"
#include "test_shader.hpp"

class renderer
{
public:
	test_shader shader;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	void render() const;
	void compile_shader();
};


#endif //CORE_RENDERER_HPP
