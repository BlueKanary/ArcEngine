#pragma once

#include "game_state.h"
#include "user_interface.h"
#include "entity.h"
#include "camera.h"

#include <allegro5/allegro_font.h>
#include <allegro5/allegro.h>
#include <vector>

void render_all(ALLEGRO_DISPLAY* display, camera& cam, game_state& state, std::vector<ui_element>& ui_list, std::vector<entity>& entity_list);

void render_ui(std::vector<ui_element>& ui_list);
void render_entity(std::vector<entity>& entity_list, camera& cam, ALLEGRO_FONT* font);
