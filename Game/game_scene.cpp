#include "game_scene.h"
#include "player.h"
#include "background.h"
//#include "spikes.h"

Game_Scene::Game_Scene()
	
	: Scene("Game")
{

	Game_Object* player = new Player("Player");
	_game_objects[player->id()] = player;

	//Game_Object* spikes_entry = new Spikes_Entry();
	//_game_objects[spikes_entry->id()] = spikes_entry;

	Game_Object* background = new Background("Background2");
	_game_objects[background->id()] = background;

	}


Game_Scene::~Game_Scene()
{
}

void Game_Scene::update(SDL_Window*)
{
}