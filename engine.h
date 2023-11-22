#pragma once

#include "event_handler.h"

#include <allegro5/allegro.h>

// Holds all non-game-specific functions and data

static struct engine {

	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_TIMER* tick;

	bool fullscreen = false; // temp

	event ev; // may change for array later

	void initialize_allegro();

	void create_display();
	void create_event_stream();

};
