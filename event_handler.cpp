#include "event_handler.h"

#include <iostream>
event event_handler(ALLEGRO_EVENT_QUEUE* event_queue, event ev) {

	ev.type = "NULL";

	ALLEGRO_EVENT al_event;
	
	if (al_get_next_event(event_queue, &al_event)) {

		if (al_event.type == ALLEGRO_EVENT_KEY_DOWN) { // Keyboard Events

			switch (al_event.keyboard.keycode) {

			case ALLEGRO_KEY_UP:		// MOVEMENT codes are used for determining movement directions and menu selectors
				ev.type = "MOVEMENT";
				ev.held_keys[KEY_UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				ev.type = "MOVEMENT";
				ev.held_keys[KEY_DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				ev.type = "MOVEMENT";
				ev.held_keys[KEY_LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				ev.type = "MOVEMENT";
				ev.held_keys[KEY_RIGHT] = true;
				break;

			case ALLEGRO_KEY_Z:		// Zoom Test Key
				ev.held_keys[KEY_Z] = true;
				break;
			case ALLEGRO_KEY_X:		// Zoom Test Key
				ev.held_keys[KEY_X] = true;
				break;

			case ALLEGRO_KEY_ESCAPE:	// EXIT code can be used for leaving menus, pausing, or exiting the game
				ev.type = "EXIT";
				break;
			}
		}

		if (al_event.type == ALLEGRO_EVENT_KEY_UP) { // Key up events

			switch (al_event.keyboard.keycode) {

				case ALLEGRO_KEY_UP:
					ev.held_keys[KEY_UP] = false;
					break;
				case ALLEGRO_KEY_DOWN:
					ev.held_keys[KEY_DOWN] = false;
					break;
				case ALLEGRO_KEY_LEFT:
					ev.held_keys[KEY_LEFT] = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					ev.held_keys[KEY_RIGHT] = false;
					break;

				case ALLEGRO_KEY_Z:		// Zoom Test Key
					ev.held_keys[KEY_Z] = false;
					break;
				case ALLEGRO_KEY_X:		// Zoom Test Key
					ev.held_keys[KEY_X] = false;
					break;
			}
		}

		// Mouse Events
		if (al_event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {

			switch (al_event.mouse.button) {

				case 1:	
					ev.held_keys[MOUSE_1] = true;
				case 2:
					ev.held_keys[MOUSE_2] = true;
			}
		}

		if (al_event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {

			switch (al_event.mouse.button) {

				case 1:
					ev.held_keys[MOUSE_1] = false;
				case 2:
					ev.held_keys[MOUSE_2] = false;
			}
		}

		if (al_event.type == ALLEGRO_EVENT_MOUSE_AXES) {

			ev.mouse = al_event.mouse;

		}

		if (al_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { // Alternative exit code. Will replace with a QUIT code for ending process
			ev.type = "EXIT";
		}

		if (al_event.type == ALLEGRO_EVENT_TIMER) { // RENDER_FRAME calls the renderer each frame
			ev.type = "RENDER_FRAME";
		}

	}

	return ev;

}