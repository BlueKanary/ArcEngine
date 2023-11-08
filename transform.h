#pragma once

#include "vector.h"

struct transform { // The point to transform from and by how much. Think of a hinge vs actual position of object

	vector position; // Transform origin
	vector scale;
	float rotation; // Degrees

	transform(vector position, vector scale, float rotation);
	transform();

};
