#include "pinky.h"

	Pinky::Pinky(std::string id)
	: Game_Object(id, "Texture.Pinky")
{
	
	_translation = Vector_2D(350, 300);

}
	Pinky::~Pinky()
{
}
void Pinky::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}

