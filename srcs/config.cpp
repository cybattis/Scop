//
// Created by Cyril Battistolo on 21/12/2022.
//

#include "config.hpp"

bool config::is_wireframe = false;

void config::toggle_wireframe()
{
	is_wireframe = !is_wireframe;
}
