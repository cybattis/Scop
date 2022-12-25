//
// Created by Cyril Battistolo on 25/12/2022.
//

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"


class Texture
{
	int width{}, height{}, nrChannels{};
	unsigned char *data{};

public:
	GLuint ID{};

	Texture() = default;
	explicit Texture(const std::string& path, int wrapping = GL_REPEAT);
};


#endif //TEXTURE_HPP
