#pragma once

#include <allegro5/allegro.h>

struct ui_element {

	int x;
	int y;

	int width;
	int height;

	ALLEGRO_COLOR color;
	ALLEGRO_BITMAP* image; // For attaching a ui Image eventually

	// Script reference

	ui_element(int x, int y, int w, int h, ALLEGRO_COLOR c, ALLEGRO_BITMAP* b = NULL) {
		ui_element::x = x;
		ui_element::y = y;
		ui_element::width = w;
		ui_element::height = h;
		ui_element::color = c;
	}

	ui_element() {}

	bool is_mouse_hover(ALLEGRO_MOUSE_EVENT m) {
		return m.x > x && m.x < x + width && m.y > y && m.y < y + height;
	}
};
