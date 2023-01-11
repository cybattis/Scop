//
// Created by Cyril Battistolo on 18/12/2022.
//

#define GL_SILENCE_DEPRECATION

#include "core.hpp"

int main()
{
	Application app(1440, 960, "ft_scop"); // create and init application

	std::cout << "--- START LOOP ---" << std::endl;
	app.update();
	std::cout << "--- END LOOP ---" << std::endl;
}
