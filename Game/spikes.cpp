//#include "spikes.h"
//#include "scene.h"
//
//Spikes_Entry::Spikes_Entry()
//	: Game_Object("Spikes.Entry", "Texture.Spikes.Entry")
//{
//	_width = 200;
//	_height = 200;
//	_translation = Vector_2D(50, 300);
//}
//
//Spikes_Entry::~Spikes_Entry()
//{
//
//}
//void Spikes_Entry::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config)
//{
//	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
//	texture->update_frame(milliseconds_to_simulate);
//
//	Game_Object::render(milliseconds_to_simulate, assets, renderer, config);
//}
//
//void Spikes_Entry::simulate_AI(Uint32, Assets*, Input*, Scene* scene)
//{
//	Game_Object* player = scene->get_game_object("Player");
//
//	
//}