//
// Created by Cyril Battistolo on 21/12/2022.
//

#include "core_renderer.hpp"

renderer::renderer() :
	clearColor(glm::vec4(0.25f, 0.25f, 0.26f, 1.00f)),
	camera(Camera())
{
	gridShader = Shader("shader/default_vertex_shader.vert", "shader/grid_fragment_shader.frag");
	activeShader = Shader("shader/default_vertex_shader.vert", "shader/default_fragment_shader.frag");

	computeObjects();
	generateGrid(150);
}

void renderer::render()
{
	glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	camera.updateZoom();

	drawGrid();

	obj.draw(activeShader, camera);
}

void renderer::computeObjects()
{
	std::cout << "Commputing object..." << std::endl;
	obj = Model("assets/box_textured.obj");
}

void renderer::drawGrid() const
{
	gridShader.use(camera);
	gridShader.setMat4("view", camera.getView());

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(50.0f, 0.0f, 75.5f));
	gridShader.setMat4("model", model);

	glBindVertexArray(grid_VAO);
	glDrawElements(GL_LINES, static_cast<GLsizei>(grid_indices.size()), GL_UNSIGNED_INT, 0);
}

void renderer::generateGrid(int size)
{
	vertexArray vertices;

	for (int i = -size; i <= size; ++i)
	{
		for (int j = -size; j <= size; ++j)
		{
			Vertex v = {{(float) j, 0.0f, (float) i},
						{1.0f, 1.0f, 1.0f},
						{0.0f, 0.0f, 0.0f},
						{0.0f, 0.0f}};
			vertices.emplace_back(v);
		}
	}

	for (int j = 0; j <= size + 1; j++)
	{
		for (int i = 0; i <= size + 1; i++)
		{
			int row = j * (size * 2 + 1);
			int nextRow = (j + 1) * (size * 2 + 1);

			grid_indices.push_back(i + row);
			grid_indices.push_back(i + row + 1);

			grid_indices.push_back(i + row);
			grid_indices.push_back(i + nextRow);

			grid_indices.push_back(i + row + 1);
			grid_indices.push_back(i + nextRow + 1);

			grid_indices.push_back(i + nextRow);
			grid_indices.push_back(i + nextRow + 1);

		}
	}

	GLuint VBO, EBO;
	glGenVertexArrays(1, &grid_VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(grid_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER,
			vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			static_cast<GLsizei>(grid_indices.size() * sizeof(GLuint)), &grid_indices[0], GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
	// vertex colors
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
