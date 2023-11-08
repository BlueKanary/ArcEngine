#pragma once

#include "vector.h"
#include "transform.h"

#include <cmath>
#include <stdexcept>

namespace vmath {

	static float length(vector vec) { // Vector calculations
		return sqrtf(vec.x * vec.x + vec.y * vec.y);
	}
	static float length_squared(vector vec) {
		return vec.x * vec.x + vec.y * vec.y;
	}
	static float distance(vector vec1, vector vec2) {
		return length(vec1 - vec2);
	}
	static float distance_squared(vector vec1, vector vec2) {
		return length_squared(vec1 - vec2);
	}
	static vector normalize(vector vec) {
		return vector(vec.x / length(vec), vec.y / length(vec));
	}
	static float dot_product(vector vec1, vector vec2) {
		return vec1.x * vec2.x + vec1.y * vec2.y;
	}
	static float cross_product(vector vec1, vector vec2) { // Only the z result
		return vec1.x * vec2.y - vec1.y * vec2.x;
	}
	   
	static float clamp(float value, float min, float max) { // clamps a value to between a min and max

		if (min > max) throw std::out_of_range("Min greater than max");

		if (min == max) value = min;
		if (min > value) value = min;
		if (max < value) value = max;

		return value;

	}

	static float degree_to_radian(float degrees) {

		return degrees * (3.1415 / 180);
	}

	static float radian_to_degree(float radian) {

		return radian * (180 / 3.1415);
	}

	static vector transform_vector(vector vec, transform t, vector position) {

		vector pivot = position + t.position;

		return vector( // Takes the relative position, adds vector x - "hinge" x * rotation, add/sub vector y - "hinge" y * rotation
			pivot.x + (vec.x - pivot.x) * std::cos(t.rotation) - (vec.y - pivot.y) * std::sin(t.rotation),
			pivot.y + (vec.x - pivot.x) * std::sin(t.rotation) + (vec.y - pivot.y) * std::cos(t.rotation)
		);
	}

};
