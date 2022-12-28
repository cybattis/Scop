//
// Created by Cyril Battistolo on 19/12/2022.
//

#include "cube_textured.hpp"

cube_textured::cube_textured() : VAO(0), VBO(0), mixValue(0.25f), transform(glm::mat4(1.0f))
{
	texture1 = Texture("assets/textures/container.jpg", "diffuse", GL_CLAMP_TO_EDGE);
	texture2 = Texture("assets/textures/awesomeface.png", "diffuse", GL_CLAMP_TO_EDGE);

	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void cube_textured::render(Shader shader)
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture1.id);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2.id);

	shader.setFloat("mixValue", mixValue);

	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f));
	view = glm::rotate(view, glm::radians(10.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	shader.setMat4("view", view);

	glm::mat4 projection;
	projection = glm::perspective(glm::radians(70.0f), 1440.0f / 960.0f, 10.0f, 100.0f);
	shader.setMat4("projection", projection);

	glBindVertexArray(VAO);
	for(unsigned int i = 0; i < 10; i++)
	{
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, cubePositions[i]);
		if (i % 2)
			model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		float angle = 20.0f * i;
		model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
		shader.setMat4("model", model);

		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}
