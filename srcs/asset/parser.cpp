//
// Created by Cyril Battistolo on 28/12/2022.
//

#include "parser.hpp"

std::stringstream Parser::read_file(const std::string& path)
{
	std::ifstream     file;
	std::stringstream stream;

	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		file.open(path);
		stream << file.rdbuf();
		file.close();
	}
	catch (std::ifstream::failure &e) {
		std::cout << "Error: could not open file: " << path << std::endl;
	}

	return stream;
}

dataMeshes Parser::parse_file(const std::string &path)
{
	std::stringstream stream(read_file(path));
	raw_index_array   raw_index;
	raw_data          raw_data;
	dataMesh          mesh;
	dataMeshes        meshes;

	while (stream.good())
	{
		std::string line;
		std::getline(stream, line);

		if (line.substr(0, 2) == "o ") {
			mesh.name = line.substr(2);
			mesh.path = path;
		}
		else if (line.substr(0, 2) == "v ")
		{
			std::istringstream v(line.substr(2));
			glm::vec3 vertex;
			v >> vertex.x; v >> vertex.y; v >> vertex.z;
			raw_data.v_Position.push_back(vertex);
		}
		else if (line.substr(0, 3) == "vn ")
		{
			std::istringstream vn(line.substr(3));
			glm::vec3 normal;
			vn >> normal.x; vn >> normal.y; vn >> normal.z;
			raw_data.v_Normal.push_back(normal);
		}
		else if (line.substr(0, 3) == "vt ")
		{
			std::istringstream vt(line.substr(3));
			glm::vec2 texCoord;
			vt >> texCoord.x; vt >> texCoord.y;
			raw_data.v_TexCoord.push_back(texCoord);
		}
		else if (line.substr(0, 2) == "f ")
		{
			std::istringstream ff(line.substr(2));
			raw_index.push_back(parse_face(ff));

			std::string face_line;
			while (std::getline(stream, face_line) && face_line.substr(0, 2) == "f ")
			{
				std::istringstream f(face_line.substr(2));
				raw_index.push_back(parse_face(f));
			}
			process_raw_data(mesh, raw_index, raw_data);
			if (mesh.name.empty())
				mesh.name = path.substr(path.find_last_of('/') + 1);
			meshes.push_back(mesh);
		}
	}

	return meshes;
}

void Parser::process_raw_data(dataMesh& data_mesh, const raw_index_array& raw_index, raw_data raw_data)
{
	GLuint index = 0;
	for (const auto & i : raw_index)
	{
		for (int j = 0; j < 3; ++j, ++index)
		{
			Vertex v;

			data_mesh.indices.push_back(index);

			v.position = raw_data.v_Position[i.position_index[j] - 1];
			v.color	= glm::vec3 { 1.0f, 1.0f, 1.0f };

			if (i.normal_index[j] != 0)
				v.normal = raw_data.v_Normal[i.normal_index[j] - 1];
			else
				v.normal = glm::vec3 { 0.0f, 0.0f, 0.0f };

			if (i.uv_index[j] != 0)
				v.texCoords = raw_data.v_TexCoord[i.uv_index[j] - 1];
			else
				v.texCoords = glm::vec2 { 0.0f, 0.0f };

			data_mesh.vertices.push_back(v);
		}
	}
}

Parser::vertIndex Parser::parse_face(std::istringstream& f)
{
	Parser::vertIndex face{};

	for (int i = 0; i < 3; i++)
	{
		f >> face.position_index[i];
		if (f.peek() == '/')
		{
			f.ignore();
			if (f.peek() != '/')
				f >> face.uv_index[i];
			if (f.peek() == '/')
			{
				f.ignore();
				f >> face.normal_index[i];
			}
		}
	}
	return face;
}
