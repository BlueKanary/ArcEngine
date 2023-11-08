#pragma once

#include <allegro5/allegro.h>

void initialize_allegro();

static struct engine {

	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_TIMER* tick;

	void create_display();
	void create_event_stream();

};
