#pragma once

#include <allegro5/allegro.h>

enum KEY_TYPES {
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_Z,
	KEY_X,

	MAX_HELD_KEYS
};

struct event {
	const char* type = "NULL";

	bool held_keys[MAX_HELD_KEYS] = {false};

};

event event_handler(ALLEGRO_EVENT_QUEUE* event_queue, event ev);
