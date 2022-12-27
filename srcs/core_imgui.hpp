//
// Created by Cyril Battistolo on 19/12/2022.
//

#ifndef CORE_IMGUI_HPP
#define CORE_IMGUI_HPP

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "glm/glm.hpp"

class UI
{
	bool is_wireframe = false;

public:
	explicit UI(GLFWwindow *window);
	~UI();

	void setup(int width, int height, float* mixValue); // TODO: replace third parameter by object/asset type
	void render();

private:
	void update_event();
};

#endif //CORE_IMGUI_HPP
