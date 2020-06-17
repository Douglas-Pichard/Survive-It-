#include "spikes.h"


Spikes::Spikes(std::string id)
	: Game_Object(id, "Texture.Spike")
{
	_width = 100;
	_height = 1800;
	_translation = Vector_2D(-5, -500);
	_collider.set_radius(_width / 100.0f);
	_collider.set_translation(Vector_2D(_width / 20.0f, (float)600));
}
Spikes::~Spikes()
{
}
void Spikes::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}