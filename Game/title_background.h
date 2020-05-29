#pragma once

#include "game_object.h"

class Title_Background : public Game_Object
{
public:
	Title_Background(std::string id);
	~Title_Background();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
};