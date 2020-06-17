#include "enemy.h"
#include "projectile.h"
#include <ctime>


Enemy::Enemy()
	: Game_Object("BlueBoy", "Texture.Blue")
{
	_width = 100;
	_height = 100;
	_translation = Vector_2D(600,10);

	_time_until_spawn_projectile = 1000;
	_time_until_spawn_projectile2 = 2000;
	_flip = SDL_FLIP_HORIZONTAL;
}

Enemy::~Enemy()
{

}



void Enemy::simulate_AI(Uint32 milliseconds_to_simulate, Assets*, Input*, Scene* scene)
{
	_time_until_spawn_projectile -= milliseconds_to_simulate;

	if (_time_until_spawn_projectile <= 0)
	{
		Projectile* projectile = new Projectile("Projectile.Time." + std::to_string(time(0)));
		Game_Object* player = scene->get_game_object("Player");

		Vector_2D this_to_player = player->translation() - _translation;
		this_to_player.normalize();
		this_to_player.scale(0.25);

		projectile->set_translation(_translation);
		projectile->set_velocity(this_to_player);

		scene->add_game_object(projectile);

		_time_until_spawn_projectile = 1000;
	}
	_time_until_spawn_projectile -= milliseconds_to_simulate;

	if (_time_until_spawn_projectile2 <= 0)
	{
		Projectile* projectile2 = new Projectile("Projectile.Time." + std::to_string(time(0)));
		Game_Object* player = scene->get_game_object("Player");

		Vector_2D this_to_player = player->translation() - _translation;
		this_to_player.normalize();
		this_to_player.scale(0.25);

		projectile2->set_translation(_translation);
		projectile2->set_velocity(this_to_player);

		scene->add_game_object(projectile2);

		_time_until_spawn_projectile = 5000;
	}
}