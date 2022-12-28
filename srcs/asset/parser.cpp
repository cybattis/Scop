//
// Created by Cyril Battistolo on 28/12/2022.
//

#include "parser.hpp"

typedef std::vector<GLuint>    index_array;

std::stringstream Parser::read_file(const std::string& path)
{
	std::ifstream file;
	std::stringstream stream;

	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		file.open(path);
		stream << file.rdbuf();
		file.close();
	}
	catch (std::ifstream::failure &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return stream;
}

Parser::dataMesh* Parser::parse_file(const std::string &path)
{
	std::stringstream stream(read_file(path));
	auto *mesh = new dataMesh();
	std::vector<raw_index_array> raw_index;

	while (stream.good())
	{
		std::string line;
		std::getline(stream, line);

		if (line.substr(0, 2) == "v ")
		{
			std::istringstream v(line.substr(2));
			glm::vec3 vertex;
			v >> vertex.x; v >> vertex.y; v >> vertex.z;
			mesh->v_Position.push_back(vertex);
		}
		else if (line.substr(0, 3) == "vn ")
		{
			std::istringstream vn(line.substr(3));
			glm::vec3 normal;
			vn >> normal.x; vn >> normal.y; vn >> normal.z;
			mesh->v_Normal.push_back(normal);
		}
		else if (line.substr(0, 3) == "vt ")
		{
			std::istringstream vt(line.substr(3));
			glm::vec2 texCoord;
			vt >> texCoord.x; vt >> texCoord.y;
			mesh->v_TexCoord.push_back(texCoord);
		}
		else if (line.substr(0, 2) == "f ")
		{
			std::istringstream f(line.substr(2));
			raw_index_array face;

			while (f >> face.back().vertex_index)
			{
				face.back().vertex_index--;
				if (f.peek() == '/')
				{
					f.ignore();
					if (f.peek() != '/')
					{
						f >> face.back().uv_index;
						face.back().uv_index--;
					}
					if (f.peek() == '/')
					{
						f.ignore();
						f >> face.back().normal_index;
						face.back().normal_index--;
					}
				}
				if (f.peek() == ' ')
					f.ignore();
			}
			raw_index.push_back(face);
		}
	}
//	mesh->indices = find_indices(raw_index);

	return mesh;
}

index_array Parser::find_indices(raw_index_array raw_index)
{
	index_array indices;



	return indices;
}
