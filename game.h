#pragma once

#include <engine.h>
#include <camera.h>
#include <game_state.h>
#include <user_interface.h>
#include <entity.h>

#include <vector>

// Holds game specific functions and data

struct game {

	engine backend;
	camera gamecam;

	game_state state = GAMEPLAY;

	std::vector<ui_element> ui_list;
	std::vector<entity> entity_list;
	entity* player;

	void game_loop();
	void resize_window();

private:

	void event_resolution();


};