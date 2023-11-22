#pragma once

class camera {
	
public:

	int x;
	int y;
	float zoom;

	camera(int x, int y, float z = 1) {

		camera::x = x;
		camera::y = y;
		camera::zoom = z;

	}

	camera() {}

};