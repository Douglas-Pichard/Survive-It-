#include "game_object.h"
class Enemy : public Game_Object
{
public:
	Enemy();
	~Enemy();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;

private:
	int _time_until_spawn_projectile;
	int _time_until_spawn_projectile2;
};


