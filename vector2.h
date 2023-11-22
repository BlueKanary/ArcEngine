#pragma once

struct vector2 {

	float x = 0;
	float y = 0;

	vector2(float x, float y) { this->x = x; this->y = y; }
	vector2() {}

	vector2 friend operator + (vector2 const& vec1, vector2 const& vec2) { // Addition, Subtraction operators
		return vector2(vec1.x + vec2.x, vec1.y + vec2.y);
	}
	void friend operator += (vector2 &vec1, vector2 const& vec2) {
		(vec1.x += vec2.x, vec1.y += vec2.y);
	}
	vector2 operator - (vector2 const& vec) { // Negative operator
		return vector2(-vec.x, -vec.y);
	}
	vector2 friend operator * (vector2 const& vec, float scalar) {		// Multiplication, Division operators
		return vector2(vec.x * scalar, vec.y * scalar);
	}
	vector2 friend operator / (vector2 const& vec, float scalar) {
		return vector2(vec.x / scalar, vec.y / scalar);
	}
	bool equals(vector2 other) {											// Comparison operator
		return vector2::x == other.x && vector2::y == other.y;
	}
};

static const vector2 V_ZERO = vector2(0, 0);