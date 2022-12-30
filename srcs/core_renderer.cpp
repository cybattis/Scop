//
// Created by Cyril Battistolo on 21/12/2022.
//

#include "core_renderer.hpp"

renderer::renderer() : clear_color(glm::vec4(0.45f, 0.55f, 0.60f, 1.00f))
{
	activeShader = Shader("shader/default_vertex_shader.vert", "shader/default_fragment_shader.frag");
	activeShader.use();

	computeObjects();

	cam = Camera();
	activeShader.setMat4("view", cam.getView());

	glm::mat4 projection;
	projection = glm::perspective(glm::radians(45.0f), 1440.0f / 960.0f, 1.0f, 200.0f);
	activeShader.setMat4("projection", projection);
}

void renderer::render()
{
	glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	activeShader.setMat4("view", cam.getView());
	obj.Draw(activeShader);
}

void renderer::computeObjects()
{
	std::cout << "Commputing object..." << std::endl;
	obj = Model("assets/box_textured.obj");
}
