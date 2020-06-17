#include "title_background.h"

Title_Background::Title_Background(std::string id)
	: Game_Object(id, "Texture.Background2")
{


	_width = 1400;
	_height = 800;
}
Title_Background::~Title_Background()
{
}
void Title_Background::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}