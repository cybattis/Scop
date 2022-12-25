//
// Created by Cyril Battistolo on 19/12/2022.
//

#include "multi_triangles.hpp"

void multi_triangles::setup()
{
	for (int i = 0; i < 2; i++)
	{
		glGenBuffers(1, &VBO[i]);
		glGenVertexArrays(1, &VAO[i]);

		glBindVertexArray(VAO[i]);
		glBindBuffer(GL_ARRAY_BUFFER, VBO[i]);

		if (i == 0)
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_1), vertices_1, GL_STATIC_DRAW);
		else
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_2), vertices_2, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
		glEnableVertexAttribArray(0);
	}
}

void multi_triangles::render() const
{
	for (int i = 0; i < 2; i++)
	{
		glUseProgram(program[i]);
		glBindVertexArray(VAO[i]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
}

void multi_triangles::compile_shader()
{
	// Create the vertex shader
	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_shader_source, nullptr);
	glCompileShader(vertex_shader);
	// Check for shader compile errors
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
	if(!success) {
		glGetShaderInfoLog(vertex_shader, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	for (int i = 0; i < 2; i++)
	{    // Create the fragment shader
		fragment_shader[i] = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment_shader[i], 1, &fragement_shader_source[i], nullptr);
		glCompileShader(fragment_shader[i]);
		// Check for shader compile errors
		glGetShaderiv(fragment_shader[i], GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment_shader[i], 512, nullptr, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		// Create the program
		program[i] = glCreateProgram();
		glAttachShader(program[i], vertex_shader);
		glAttachShader(program[i], fragment_shader[i]);
		glLinkProgram(program[i]);
		glGetProgramiv(program[i], GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(program[i], 512, nullptr, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKAGE\n" << infoLog << std::endl;
		}
		glDeleteShader(fragment_shader[i]);
	}
	glDeleteShader(vertex_shader);
}
