//
// Created by Cyril Battistolo on 28/12/2022.
//

#ifndef PARSER_HPP
#define PARSER_HPP

#include "glad/glad.h"

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class Parser
{
	typedef std::vector<glm::vec3> vec3_array;
	typedef std::vector<glm::vec2> vec2_array;
	typedef std::vector<GLuint>    index_array;

	struct Index
	{
		GLuint vertex_index;
		GLuint uv_index;
		GLuint normal_index;
	};
	typedef std::vector<Index>     raw_index_array;

public:
	struct dataMesh {
		std::string  name;
		std::string  path;

		vec3_array   v_Position;
		vec3_array   v_Color;
		vec3_array   v_Normal;
		vec2_array   v_TexCoord;

		index_array  indices;
	};

	static dataMesh* parse_file(const std::string& path);

private:
	Parser() = default;
	static std::stringstream read_file(const std::string& path);
	static index_array find_indices(raw_index_array raw_index);
};


#endif //PARSER_HPP
