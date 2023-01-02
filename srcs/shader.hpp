//
// Created by Cyril Battistolo on 23/12/2022.
//

#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>

#include <iostream>
#include <fstream>
#include <sstream>

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "components/camera.hpp"

class Shader
{
public:
	unsigned int id; // the program ID

	Shader() = default;
	Shader(const char* vertexPath, const char* fragmentPath);

	void use(Camera camera) const;

	void setBool(const std::string &name, const bool& value) const;
	void setInt(const std::string &name, const int& value) const;
	void setFloat(const std::string &name, const float& value) const;
	void setVec2(const std::string &name, const glm::vec2 &value) const;
	void setVec3(const std::string &name, const glm::vec3 &value) const;
	void setVec4(const std::string &name, const glm::vec4 &value) const;
	void setMat4(const std::string &name, const glm::mat4& value) const;

private:
	static void checkCompileErrors(unsigned int shader, const std::string& type);
};


#endif //SHADER_HPP
