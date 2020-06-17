#include "game_scene.h"
#include "player.h"
#include "background.h"
#include "enemy.h"
#include "scene.h"
#include "title_scene.h"

Game_Scene::Game_Scene()
	: Scene("Game")
{
	Game_Object* player = new Player("Player");
	_game_objects[player->id()] = player;

	Game_Object* background = new Background("Background4");
	_game_objects[background->id()] = background;

	Game_Object* enemy = new Enemy();
	_game_objects[enemy->id()] = enemy;

	std::stack<Scene*> scenes;
	scenes.push(new Title_Scene);
	Game_Scene* game_scene = (Game_Scene*)scenes.top();
	scenes.pop();
	delete game_scene;
}



Game_Scene::~Game_Scene()
{
}

void Game_Scene::update(SDL_Window*)
{
}