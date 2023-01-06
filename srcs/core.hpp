//
// Created by Cyril Battistolo on 19/12/2022.
//

#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core_imgui.hpp"
#include "renderer.hpp"
#include "Global.hpp"

class UI;

class Application
{

public:
	GLFWwindow *window{};
	renderer render;
	std::unique_ptr<UI> ui;

	explicit Application(int width = 960, int height = 540, const char *title = "My window");
	~Application();

	void main_loop();

private:
	GLFWwindow* init_glfw(const char *title, int width, int height) const;

	static void error_callback(int error, const char *description);
	static void window_refresh_callback(GLFWwindow* window);
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
	static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
	static void mouse_position_callback(GLFWwindow* window, double xpos, double ypos);
	static void mouse_scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

	static void process_input(GLFWwindow *window);

	void print_info_config(const char *title) const;

	float lastFrame = 0.0f;
	void updateDeltaTime();

	bool lock_mouse = false;

	bool firstMouse = true;
	float yaw = -90.0f;
	float pitch = 0.0f;
	double lastX = static_cast<double>(windowWidth) / 2, lastY = static_cast<double>(windowHeight) / 2;
};


#endif //CORE_HPP
