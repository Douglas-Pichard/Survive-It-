#include "game_scene.h"
#include "player.h"
//#include "spikes.h"
#include "portal_entry.h"
#include "portal_exit.h"

Game_Scene::Game_Scene()
	: Scene("Game")
{
	Game_Object* player = new Player("Player");
	_game_objects[player->id()] = player;

	//Game_Object* spikes_entry = new Spikes_Entry();
	//_game_objects[spikes_entry->id()] = spikes_entry;

	Game_Object* portal_entry = new Portal_Entry();
	_game_objects[portal_entry->id()] = portal_entry;

	Game_Object* portal_exit = new Portal_Exit();
	_game_objects[portal_exit->id()] = portal_exit;
}

Game_Scene::~Game_Scene()
{
}

void Game_Scene::update(SDL_Window*)
{
}