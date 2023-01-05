//
// Created by Cyril Battistolo on 23/12/2022.
//

#include "shader.hpp"

Shader::Shader(const char *vertexPath, const char *fragmentPath, const char* name)
	: id(0), name(name)
{
	std::cout << "Compiling shader..." << std::endl;
	// Open file and compile shader
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vShaderFile.open(vertexPath);
		std::stringstream vShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		vShaderFile.close();
		vertexCode = vShaderStream.str();
	}
	catch (std::ifstream::failure &e) {
		std::cout << "Error: VERTEX_SHADER: " << e.what() << std::endl;
	}

	try
	{
		fShaderFile.open(fragmentPath);
		std::stringstream fShaderStream;
		fShaderStream << fShaderFile.rdbuf();
		fShaderFile.close();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure &e) {
		std::cout << "Error: FRAGMENT_SHADER: " << e.what() << std::endl;
	}

	const char *vShaderCode = vertexCode.c_str();
	const char *fShaderCode = fragmentCode.c_str();

	GLuint vertex, fragment;

	// Vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, nullptr);
	glCompileShader(vertex);
	// Check for shader compile errors
	checkCompileErrors(vertex, "VERTEX");

	// Fragment shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, nullptr);
	glCompileShader(fragment);
	// Check for shader compile errors
	checkCompileErrors(fragment, "FRAGMENT");

	// Shader program
	id = glCreateProgram();
	glAttachShader(id, vertex);
	glAttachShader(id, fragment);
	glLinkProgram(id);
	// Check for linking errors
	checkCompileErrors(id, "PROGRAM");

	// Delete shaders
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::use(Camera camera) const
{
	glUseProgram(id);
	setMat4("view", camera.getView());
	setMat4("projection", camera.projection);
}

void Shader::setBool(const std::string &name, const bool& value) const
{
	glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, const int& value) const
{
	glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, const float& value) const
{
	glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::setVec2(const std::string &name, const glm::vec2 &value) const
{
	glUniform2fv(glGetUniformLocation(id, name.c_str()), 1, glm::value_ptr(value));
}

void Shader::setVec3(const std::string &name, const glm::vec3 &value) const
{
	glUniform3fv(glGetUniformLocation(id, name.c_str()), 1, glm::value_ptr(value));
}

void Shader::setVec4(const std::string &name, const glm::vec4 &value) const
{
	glUniform4fv(glGetUniformLocation(id, name.c_str()), 1, glm::value_ptr(value));
}

void Shader::setMat4(const std::string &name, const glm::mat4& value) const
{
	glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::checkCompileErrors(unsigned int shader, const std::string& type)
{
	int success;
	char infoLog[1024];

	if (type == "PROGRAM")
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog
			<< "\n -- --------------------------------------------------- -- " << std::endl;
		}
		return ;
	}

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
		std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog
				  << "\n -- --------------------------------------------------- -- " << std::endl;
	}
}
