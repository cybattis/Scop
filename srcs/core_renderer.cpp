//
// Created by Cyril Battistolo on 21/12/2022.
//

#include "core_renderer.hpp"

renderer::renderer()
{
	colored_triangle = Shader("shader/triangle_colors.vert", "shader/triangle_colors.frag");
	texture_shader = Shader("shader/texture_shader.vert", "shader/texture_shader.frag");

	compute_objects();
	texture_shader.use();
	texture_shader.setInt("texture1", 0);
	texture_shader.setInt("texture2", 1);
	texture_shader.setFloat("xOffSet", rectangle_tex.xOffset);
	texture_shader.setFloat("yOffSet", rectangle_tex.yOffset);
}

void renderer::render() const
{
	float offset = -0.5f;
	glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
	glClear(GL_COLOR_BUFFER_BIT);

//	colored_triangle.use();
//	colored_triangle.setFloat("xOffset", offset);

	rectangle_tex.render(texture_shader.ID);

//	triangle.render(colored_triangle.ID);
//	rectangle.render();
}

void renderer::compute_objects()
{
	rectangle_tex = rectangle_textured();
//	triangle.generate();
//	rectangle.generate();
}
