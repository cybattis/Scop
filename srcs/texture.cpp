//
// Created by Cyril Battistolo on 25/12/2022.
//

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "texture.hpp"

#include <utility>

Texture::Texture(const std::string& path, std::string type, int wrapping) : path(path), type(std::move(type))
{
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapping);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapping);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// load and generate the texture
	stbi_set_flip_vertically_on_load(true);
	// load and generate the texture
	data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
	if (!data) {
		throw std::runtime_error("Failed to load texture");
	}

	if (path.find(".png") == std::string::npos)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	else
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);
}
