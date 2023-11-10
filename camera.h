#pragma once

#include "vector.h"

class camera {
	
public:

	vector position = V_ZERO;
	float zoom = 1;

	int width = 0;
	int height = 0;

	camera(vector position, int width, int height) {

		camera::position = position;
		camera::width = width;
		camera::height = height;

	}

	camera() {}

};