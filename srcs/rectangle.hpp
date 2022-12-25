//
// Created by Cyril Battistolo on 19/12/2022.
//

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class rectangle
{
	char infoLog[512]{};
	GLuint VAO{}, VBO{}, EBO{};

	float vertices[24] = {
			0.5f,  0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // top right
			0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // bottom right
			-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
			-0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f  // top left
	};

	unsigned int indices[6] = {  // note that we start from 0!
			0, 1, 3,   // first triangle
			1, 2, 3    // second triangle
	};

public:
	void generate();
	void render() const;
};

#endif //RECTANGLE_SHADER_HPP
