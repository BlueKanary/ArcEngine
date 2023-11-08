#pragma once

struct vector {

	float x;
	float y;

	vector(float x, float y) { this->x = x; this->y = y; }
	vector();

	vector friend operator + (vector const& vec1, vector const& vec2) { // Addition, Subtraction operators
		return vector(vec1.x + vec2.x, vec1.y + vec2.y);
	}
	void friend operator += (vector &vec1, vector const& vec2) { // Addition, Subtraction operators
		(vec1.x += vec2.x, vec1.y += vec2.y);
	}
	vector operator - (vector const& vec) { // Negative operator
		return vector(-vec.x, -vec.y);
	}
	vector friend operator * (vector const& vec, float scalar) {		// Multiplication, Division operators
		return vector(vec.x * scalar, vec.y * scalar);
	}
	vector friend operator / (vector const& vec, float scalar) {
		return vector(vec.x / scalar, vec.y / scalar);
	}
	bool equals(vector other) {											// Comparison operator
		return vector::x == other.x && vector::y == other.y;
	}
};

static const vector V_ZERO = vector(0, 0);