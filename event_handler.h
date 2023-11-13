#pragma once

#include <allegro5/allegro.h>

enum KEY_TYPES {

	KEY_ESC,
	
	KEY_LSHIFT,
	KEY_RSHIFT,
	KEY_LCTRL,
	KEY_RCTRL,
	KEY_LALT,
	KEY_RALT,

	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,

	KEY_A,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,

	MOUSE_1,
	MOUSE_2,
	MOUSE_3,

	MAX_HELD_KEYS
};

struct event {

	const char* special = "NULL"; // May create different event type for these

	bool held_keys[MAX_HELD_KEYS] = {false};
	bool pressed = false;

	ALLEGRO_MOUSE_EVENT mouse;
	void reset_mouse() { mouse.dx = 0; mouse.dy = 0; }

	//ALLEGRO_JOYSTICK_EVENT joystick;

};

void event_handler(ALLEGRO_EVENT_QUEUE* event_queue, event &ev);

// void event_mapper(event &ev);