#include "blue_boy.h"


BlueBoy::BlueBoy(std::string id)
	: Game_Object(id, "Texture.Blue")
{

	_translation = Vector_2D(350, 350);
	_collider.set_radius(_width / 5.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));
}
BlueBoy::~BlueBoy()
{
}
void BlueBoy::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}