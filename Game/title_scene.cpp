#include "title_scene.h"
#include "title_screen.h"
#include "pinky.h"
#include "title_background.h"


Title_Scene::Title_Scene()

	: Scene("Title")
{
	Game_Object* pinky = new Pinky("Pinky");
	_game_objects[pinky->id()] = pinky;

	Game_Object* title_background = new Title_Background("Background2");
	_game_objects[title_background->id()] = title_background;

	Game_Object* title_screen = new Title_Screen("");
	_game_objects[title_screen->id()] = title_screen;

	

	
	
	

}


Title_Scene::~Title_Scene()
{
}

void Title_Scene::update(SDL_Window*)
{
}