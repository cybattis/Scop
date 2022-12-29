//
// Created by Cyril Battistolo on 18/12/2022.
//

#define GL_SILENCE_DEPRECATION

#include "core.hpp"
#include "core_imgui.hpp"
#include "core_renderer.hpp"

int main()
{
	Application app(1440, 960, "ft_scop"); // create and init application
	renderer render; // create renderer

	std::cout << "--- RENDER LOOP ---" << std::endl;
	// Main loop
	while (!glfwWindowShouldClose(app.window))
	{
		glfwPollEvents();

		render.render();

		app.ui.setup(app.width, app.height, render.obj);
		app.ui.render();

		glfwSwapBuffers(app.window);
	}
	std::cout << "--- END RENDER LOOP ---" << std::endl;
}
