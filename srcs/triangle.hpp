//
// Created by Cyril Battistolo on 19/12/2022.
//

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class triangle
{
	char infoLog[512]{};
	GLuint VAO{}, VBO{};

	float vertices[18] = {
			// positions         // colors
			0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   // bottom right
			-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
			0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f    // top
	};

public:
	void generate();
	void render(unsigned int ID) const;
};

#endif //TRIANGLE_HPP
