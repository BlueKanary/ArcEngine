#include "event_handler.h"

#include <iostream>
void event_handler(ALLEGRO_EVENT_QUEUE* event_queue, event &ev) {

	ev.pressed = false;

	ALLEGRO_EVENT al_event;
	
	if (al_get_next_event(event_queue, &al_event)) {

		if (al_event.type == ALLEGRO_EVENT_KEY_DOWN) { // Keyboard Events

			switch (al_event.keyboard.keycode) {

				ev.pressed = true;

			case ALLEGRO_KEY_UP:		// MOVEMENT codes are used for determining movement directions and menu selectors
				ev.held_keys[KEY_UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				ev.held_keys[KEY_DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				ev.held_keys[KEY_LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				ev.held_keys[KEY_RIGHT] = true;
				break;

			case ALLEGRO_KEY_Z:
				ev.held_keys[KEY_Z] = true;
				break;
			case ALLEGRO_KEY_X:
				ev.held_keys[KEY_X] = true;
				break;

			case ALLEGRO_KEY_ESCAPE:
				ev.held_keys[KEY_ESC] = true;
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
				case ALLEGRO_KEY_A:
					ev.held_keys[KEY_A] = false;
					break;
				case ALLEGRO_KEY_B:
					ev.held_keys[KEY_B] = false;
					break;
				case ALLEGRO_KEY_C:
					ev.held_keys[KEY_C] = false;
					break;
				case ALLEGRO_KEY_D:
					ev.held_keys[KEY_D] = false;
					break;
				case ALLEGRO_KEY_E:
					ev.held_keys[KEY_E] = false;
					break;
				case ALLEGRO_KEY_F:
					ev.held_keys[KEY_F] = false;
					break;
				case ALLEGRO_KEY_G:
					ev.held_keys[KEY_G] = false;
					break;
				case ALLEGRO_KEY_H:
					ev.held_keys[KEY_H] = false;
					break;
				case ALLEGRO_KEY_I:
					ev.held_keys[KEY_I] = false;
					break;
				case ALLEGRO_KEY_J:
					ev.held_keys[KEY_J] = false;
					break;
				case ALLEGRO_KEY_K:
					ev.held_keys[KEY_K] = false;
					break;
				case ALLEGRO_KEY_L:
					ev.held_keys[KEY_L] = false;
					break;
				case ALLEGRO_KEY_M:
					ev.held_keys[KEY_M] = false;
					break;
				case ALLEGRO_KEY_N:
					ev.held_keys[KEY_N] = false;
					break;
				case ALLEGRO_KEY_O:
					ev.held_keys[KEY_O] = false;
					break;
				case ALLEGRO_KEY_P:
					ev.held_keys[KEY_P] = false;
					break;
				case ALLEGRO_KEY_Q:
					ev.held_keys[KEY_Q] = false;
					break;
				case ALLEGRO_KEY_R:
					ev.held_keys[KEY_R] = false;
					break;
				case ALLEGRO_KEY_S:
					ev.held_keys[KEY_S] = false;
					break;
				case ALLEGRO_KEY_T:
					ev.held_keys[KEY_T] = false;
					break;
				case ALLEGRO_KEY_U:
					ev.held_keys[KEY_U] = false;
					break;
				case ALLEGRO_KEY_V:
					ev.held_keys[KEY_V] = false;
					break;
				case ALLEGRO_KEY_W:
					ev.held_keys[KEY_W] = false;
					break;
				case ALLEGRO_KEY_X:
					ev.held_keys[KEY_X] = false;
					break;
				case ALLEGRO_KEY_Y:
					ev.held_keys[KEY_Y] = false;
					break;
				case ALLEGRO_KEY_Z:
					ev.held_keys[KEY_Z] = false;
					break;
			}
		}

		// Mouse Events
		if (al_event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {

			ev.pressed = true;

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

		/*
		if (al_event.type == ALLEGRO_EVENT_JOYSTICK_AXIS) {

			ev.mouse = al_event.mouse;

		}
		*/

		if (al_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { // Alternative exit code. Will replace with a QUIT code for ending process
			ev.special = "EXIT";
		}

		if (al_event.type == ALLEGRO_EVENT_TIMER) { // RENDER_FRAME calls the renderer each frame
			ev.special = "RENDER_FRAME";
		}

	}

}

