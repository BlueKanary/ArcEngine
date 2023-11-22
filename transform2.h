#pragma once

#include "vector2.h"

struct transform2 { // The point to transform from and by how much. Think of a hinge vs actual position of object

	vector2 position; // Transform origin
	vector2 scale;
	float rotation; // Degrees

	transform2(vector2 position, vector2 scale, float rotation) {

		transform2::position = position;
		transform2::scale = scale;
		transform2::rotation = rotation;
	}

	transform2();

};
