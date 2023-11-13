#pragma once

#include <allegro5/allegro.h>

struct ui_element {

	int x;
	int y;

	ALLEGRO_COLOR color;
	// ALLEGRO_BITMAP* --- For attaching a ui Image eventually

	int width;
	int height;

	ui_element(int x, int y, int w, int h) {
		ui_element::x = x;
		ui_element::y = y;
		ui_element::width = w;
		ui_element::height = h;
	}

	ui_element() {}

	bool is_mouse_hover(ALLEGRO_MOUSE_EVENT m) {
		return m.x > x && m.x < x + width && m.y > y && m.y < y + height;
	}
};
