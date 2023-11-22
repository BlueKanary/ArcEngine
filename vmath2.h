#pragma once

#include "vector2.h"
#include "transform2.h"

#include <cmath>
#include <stdexcept>

namespace vmath {

	static float length(vector2 vec) { // Vector calculations
		return sqrtf(vec.x * vec.x + vec.y * vec.y);
	}
	static float length_squared(vector2 vec) {
		return vec.x * vec.x + vec.y * vec.y;
	}
	static float distance(vector2 vec1, vector2 vec2) {
		return length(vec1 - vec2);
	}
	static float distance_squared(vector2 vec1, vector2 vec2) {
		return length_squared(vec1 - vec2);
	}
	static vector2 normalize(vector2 vec) {
		return vector2(vec.x / length(vec), vec.y / length(vec));
	}
	static float dot_product(vector2 vec1, vector2 vec2) {
		return vec1.x * vec2.x + vec1.y * vec2.y;
	}
	static float cross_product(vector2 vec1, vector2 vec2) { 
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

	static vector2 transform_vector(vector2 vec, transform2 t, vector2 position) {

		return vector2(
			position.x + (vec.x - position.x) * std::cos(t.rotation) - (vec.y - position.y) * std::sin(t.rotation),
			position.y + (vec.x - position.x) * std::sin(t.rotation) + (vec.y - position.y) * std::cos(t.rotation)
		);
	}

};
