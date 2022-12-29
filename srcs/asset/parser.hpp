//
// Created by Cyril Battistolo on 28/12/2022.
//

#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "glad/glad.h"
#include "vertex.hpp"

typedef std::vector<dataMesh> dataMeshes;

class Parser
{
	typedef std::vector<glm::vec3> vec3_array;
	typedef std::vector<glm::vec2> vec2_array;
	typedef std::vector<GLuint>    index_array;

	struct vertIndex
	{
		GLuint position_index[3];
		GLuint uv_index[3];
		GLuint normal_index[3];
	};
	typedef std::vector<vertIndex> raw_index_array;

public:
	struct raw_data {
		vec3_array   v_Position;
		vec3_array   v_Color;
		vec3_array   v_Normal;
		vec2_array   v_TexCoord;
		index_array  indices;
	};

	static dataMeshes parse_file(const std::string& path);

private:
	Parser() = default;
	static std::stringstream read_file(const std::string& path);
	static void process_raw_data(dataMesh& data_mesh, const raw_index_array& raw_index, raw_data raw_data);
	static vertIndex parse_face(std::istringstream& f);
};


#endif //PARSER_HPP
