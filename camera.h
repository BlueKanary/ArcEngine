#pragma once

#include "vector.h"

class camera {
	
public:

	int x;
	int y;
	float zoom = 1;

	int width;
	int height;

	camera(int x, int y, int width, int height) {

		camera::x = x;
		camera::y = y;
		camera::width = width;
		camera::height = height;

	}

	camera() {}

};