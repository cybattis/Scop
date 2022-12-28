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
public:
	GLuint id{};
	std::string path;
	std::string type{};

	Texture() = default;
	explicit Texture(const std::string& path, std::string type, int wrapping = GL_REPEAT);

private:
	int width{}, height{}, nrChannels{};
	unsigned char *data{};
};


#endif //TEXTURE_HPP
