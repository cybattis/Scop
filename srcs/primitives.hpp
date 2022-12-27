//
// Created by Cyril Battistolo on 27/12/2022.
//

#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

namespace Triangle
{

	float vertex[] = {
			0.5f, -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			0.0f,  0.5f, 0.0f,
	};

	float texture[] = {
			1.0f, 1.0f,
			1.0f, 0.0f,
			0.0f, 0.0f,
	};

}

namespace square
{
	float vertex[] = {
			0.5f, -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			0.0f,  0.5f, 0.0f,
	};

	float texture[] = {
			1.0f, 1.0f,
			1.0f, 0.0f,
			0.0f, 0.0f,
	};

	unsigned int indices[] = {
			0, 1, 3,
			1, 2, 3
	};
}

#endif //PRIMITIVES_HPP
