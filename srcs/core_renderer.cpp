//
// Created by Cyril Battistolo on 21/12/2022.
//

#include "core_renderer.hpp"

renderer::renderer() : cube(Model("assets/box.obj"))
{
	std::cout << "Compiling shader..." << std::endl;
	texture_shader = Shader("shader/default_vertex_shader.vert", "shader/default_fragment_shader.frag");

	compute_objects();

	texture_shader.use();

	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f));
	view = glm::rotate(view, glm::radians(10.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	texture_shader.setMat4("view", view);

	glm::mat4 projection;
	projection = glm::perspective(glm::radians(70.0f), 1440.0f / 960.0f, 1.0f, 200.0f);
	texture_shader.setMat4("projection", projection);
}

void renderer::render()
{
	glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
	model = glm::rotate(model, glm::radians(35.0f), glm::vec3(1.0f, 0.3f, 0.5f));
	texture_shader.setMat4("model", model);

	cube.Draw(texture_shader);
}

void renderer::compute_objects()
{
	std::cout << "Commputing objects..." << std::endl;
	cube_tex = cube_textured();
}
