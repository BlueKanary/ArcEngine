#pragma once

struct entity {

	int x;
	int y;
	int z;

	entity(int x, int y) {
		entity::x = x;
		entity::y = y;
	}

	void move_to(int x, int y) {
		entity::x = x;
		entity::y = y;
	}

	void shift(int x, int y) {
		entity::x += x;
		entity::y += y;
	}

};