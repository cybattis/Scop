//
// Created by Cyril Battistolo on 19/12/2022.
//

#ifndef RECTANGLE_TEXTURED_HPP
#define RECTANGLE_TEXTURED_HPP

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "texture.hpp"

class rectangle_textured
{
	char infoLog[512]{};
	GLuint VAO{}, VBO{}, EBO{};
	Texture texture1;
	Texture texture2;

public:
	float xOffset{};
	float yOffset{};
	float mixValue{};

private:
	float vertices[32] = {
		// positions          // colors           // texture coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   0.75f, 0.75f, // top right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   0.75f, 0.25f, // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.25f, 0.25f, // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.25f, 0.75f  // top left
	};

	unsigned int indices[6] = {  // note that we start from 0!
			0, 1, 3,   // first triangle
			1, 2, 3    // second triangle
	};

public:
	rectangle_textured();
	void render(const unsigned int ID) const;
};

#endif //RECTANGLE_TEXTURED_HPP
