#pragma once

#include "title_screen.h"

Title_Screen::Title_Screen(std::string id)
	: Game_Object(id, "Texture.Title.Background")
{
	_translation = Vector_2D(280, 100);
	_width = 800;
	_height = 500;

}
Title_Screen::~Title_Screen()
{
}
void Title_Screen::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config);
}

void Title_Screen::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}
