//
// Created by Cyril Battistolo on 19/12/2022.
//

#ifndef TEST_SHADER_HPP
#define TEST_SHADER_HPP

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "config.hpp"

class test_shader
{
	int  success;
	char infoLog[512];
	GLuint VAO{}, VBO{}, EBO{}, vertex_shader{}, fragment_shader{}, program{};

	float vertices[12] = {
			0.5f,  0.5f, 0.0f,  // top right
			0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  // bottom left
			-0.5f,  0.5f, 0.0f   // top left
	};

	unsigned int indices[6] = {  // note that we start from 0!
			0, 1, 3,   // first triangle
			1, 2, 3    // second triangle
	};

	const char *vertex_shader_source =
			"#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
			"}\0";

	const char *fragement_shader_source =
			"#version 330 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
			"}\n\0";

public:
	void compile_shader();
	void setup();
	void render() const;
};

#endif //TEST_SHADER_HPP
