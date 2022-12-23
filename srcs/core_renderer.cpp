//
// Created by Cyril Battistolo on 21/12/2022.
//

#include "core_renderer.hpp"

void renderer::render() const
{
	glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
	glClear(GL_COLOR_BUFFER_BIT);

	triangles.render();
}

void renderer::compile_shader()
{
	triangles.compile_shader();
	triangles.setup();
}
