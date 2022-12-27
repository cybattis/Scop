//
// Created by Cyril Battistolo on 21/12/2022.
//

#include "core_renderer.hpp"

renderer::renderer()
{
	std::cout << "Compiling shader..." << std::endl;
	texture_shader = Shader("shader/default_vertex_shader.vert", "shader/default_fragment_shader.frag");

	std::cout << "Commputing objects..." << std::endl;
	compute_objects();

	texture_shader.use();
	texture_shader.setInt("texture1", 0);
	texture_shader.setInt("texture2", 1);
}

void renderer::render()
{
	glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cube.render(texture_shader);
}

void renderer::compute_objects()
{
	cube = cube_textured();
}
