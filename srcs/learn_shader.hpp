//
// Created by Cyril Battistolo on 19/12/2022.
//

#ifndef LEARN_SHADER_HPP
#define LEARN_SHADER_HPP

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class learn_shader
{
	int  success{};
	char infoLog[512]{};
	GLuint VAO{}, VBO{}, vertex_shader{}, fragment_shader{}, program{};

	float vertices[18] = {
			// positions         // colors
			0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   // bottom right
			-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
			0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f    // top
	};

	const char *vertex_shader_source =
			"#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"layout (location = 1) in vec3 aColor;\n"
			"out vec3 ourColor;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = vec4(aPos, 1.0);\n" // see how we directly give a vec3 to vec4's constructor
			"   ourColor = aColor;\n" // set the output variable to a dark-red color
			"}\0";

	const char *fragement_shader_source =
			"#version 330 core\n"
			"out vec4 FragColor;\n"
			"in vec3 ourColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(ourColor, 1.0);\n"
			"}\n\0";

public:
	void compile_shader();
	void setup();
	void render() const;
};

#endif //LEARN_SHADER_HPP
