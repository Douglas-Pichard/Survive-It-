#include "game_scene.h"
#include "player.h"
#include "background.h"
#include "hazard2.h"

Game_Scene::Game_Scene()
	: Scene("Game")
{
	Game_Object* player = new Player("Player");
	_game_objects[player->id()] = player;

	Game_Object* background = new Background("Background2");
	_game_objects[background->id()] = background;

	int tiles_x = 20;
	int tiles_y = 10;
	int tile_scale = 50;

	for (int y = 8; y < tiles_y; ++y)
	{
		for (int x = 2; x < tiles_x; ++x)
		{
			std::string id = "lava" + std::to_string(x) + "lava" + std::to_string(y);

			std::string texture_id3 = "Texture.Lava";

			Hazard2* hazard2_3 = new Hazard2
			(id, texture_id3, Vector_2D((float)x * (float)50, (float)y + (float)500), tile_scale);
			_game_objects[hazard2_3->id()] = hazard2_3;

		}
	}

	for (int y = 8; y < tiles_y; ++y)
	{
		for (int x = 2; x < tiles_x; ++x)
		{
			std::string id = "poison" + std::to_string(x) + "poison" + std::to_string(y);

			std::string texture_id = "Texture.Poison";

			Hazard2* hazard2_1 = new Hazard2
			(id, texture_id, Vector_2D((float)x * (float)50, (float)y + (float)450), tile_scale);
			_game_objects[hazard2_1->id()] = hazard2_1;
		}
	}
	for (int y = 8; y < tiles_y; ++y)
	{
		for (int x = 2; x < tiles_x; ++x)
		{
			std::string id = "spike" + std::to_string(x) + "spike" + std::to_string(y);

			std::string texture_id2 = "Texture.Spike";

			Hazard2* hazard2_2 = new Hazard2
			(id, texture_id2, Vector_2D((float)x * (float)60, (float)y + (float)400), 150);
			_game_objects[hazard2_2->id()] = hazard2_2;

		}
	}
}

Game_Scene::~Game_Scene()
{
}

void Game_Scene::update(SDL_Window*)
{
}