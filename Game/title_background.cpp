#include "title_background.h"

Title_Background::Title_Background(std::string id)
	: Game_Object(id, "Texture.Background1")
{


	_width = 1700;
	_height = 900;
}
Title_Background::~Title_Background()
{
}
void Title_Background::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}