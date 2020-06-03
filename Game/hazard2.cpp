#include "hazard2.h"


Hazard2::Hazard2(std::string id, std::string texture_id, Vector_2D translation, int scale)
	: Game_Object(id, texture_id)
{
	_translation = translation;
	_width = scale;
	_height = scale;
}
Hazard2::~Hazard2()
{
}
void Hazard2::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}