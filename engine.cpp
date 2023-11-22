#include "engine.h"
#include "global.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

void engine::initialize_allegro() {

	al_init();

	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	al_install_keyboard();
	al_install_mouse();

}

void engine::create_display() {

	display = al_create_display(WINDOW_WIDTH, WINDOW_HEIGHT);
	al_set_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, true);

}

void engine::create_event_stream() {

	event_queue = al_create_event_queue();

	tick = al_create_timer(1.0 / FRAME_RATE); // frames per second

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(tick));

	al_start_timer(tick);

}

