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
//	Vector_2D portal_center = _translation
//		+ Vector_2D((float)_width / 2, (float)_height / 2);
//	Vector_2D player_center = player->translation()
//		+ Vector_2D((float)player->width() / 2, (float)player->height() / 2);
//
//	float distance_to_player = (portal_center - player_center).magnitude();
//
//	if (distance_to_player < 50.0f)
//	{
//		Game_Object* portal_exit = scene->get_game_object("Portal.Exit");
//		Vector_2D portal_exit_location = portal_exit->translation()
//			+ Vector_2D(100.f, 0.f);
//
//		player->set_translation(portal_exit_location);
//	}
//}