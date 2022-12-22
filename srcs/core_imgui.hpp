//
// Created by Cyril Battistolo on 19/12/2022.
//

#ifndef CORE_IMGUI_HPP
#define CORE_IMGUI_HPP

#include <iostream>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "config.hpp"

class UI
{
public:
	explicit UI(GLFWwindow *window);
	~UI();

	void setup();
	void render();

private:
};

#endif //CORE_IMGUI_HPP
