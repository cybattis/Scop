//
// Created by Cyril Battistolo on 19/12/2022.
//

#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core_imgui.hpp"

class Application
{
public:
	int width, height;
	float ratio;
	GLFWwindow *window{};
	UI ui;

	explicit Application(int width = 960, int height = 540, const char *title = "My window");
	~Application();

private:
	GLFWwindow* init_glfw(const char *title) const;

	static void error_callback(int error, const char *description);
	static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
	static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	static void mouse_position_callback(GLFWwindow* window, double xpos, double ypos);

	void print_info_config(const char *title) const;
};


#endif //CORE_HPP