#pragma once

#include <allegro5/allegro.h>

enum KEY_TYPES {
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_X,
	KEY_Z,

	MOUSE_1,
	MOUSE_2,

	MAX_HELD_KEYS
};

struct event {
	const char* type = "NULL";

	bool held_keys[MAX_HELD_KEYS] = {false};

	ALLEGRO_MOUSE_EVENT mouse;
	void reset_mouse() { mouse.dx = 0; mouse.dy = 0; }

};

event event_handler(ALLEGRO_EVENT_QUEUE* event_queue, event ev);
