#pragma once

#include "background.h"

Background::Background(std::string id)
	: Game_Object(id, "Texture.Background2")
{
	

	_width = 1400;
	_height = 800;
}
Background::~Background()
{
}
void Background::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}
