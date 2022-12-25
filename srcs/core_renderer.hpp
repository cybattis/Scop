//
// Created by Cyril Battistolo on 21/12/2022.
//

#ifndef CORE_RENDERER_HPP
#define CORE_RENDERER_HPP

#include "core.hpp"
#include "shader.hpp"

#include "multi_triangles.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "rectangle_textured.hpp"

class renderer
{
public:
	rectangle_textured rectangle_tex;
	multi_triangles multi_triangles;
	triangle triangle;
	rectangle rectangle;
	Shader colored_triangle{};
	Shader texture_shader{};
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	renderer();

	void render() const;
	void compute_objects();
};


#endif //CORE_RENDERER_HPP
