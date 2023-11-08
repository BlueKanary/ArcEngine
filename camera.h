#pragma once

#include "vector.h"
#include "global.h"

class camera {
	
public:

	vector position = V_ZERO;
	float zoom = 1;

	int width = WINDOW_WIDTH;
	int height = WINDOW_HEIGHT;

};