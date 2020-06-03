#include "hazard.h"
#include "scene.h"

Hazard::Hazard(std::string id)
	: Game_Object(id, "Texture.Lava")
{
	_height = 50;
	_width = 50;
	_translation = Vector_2D(300, 425);

}
Hazard::~Hazard()
{
}
void Hazard::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}