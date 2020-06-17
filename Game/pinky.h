#include "game_object.h"

class Pinky : public Game_Object
{
public:
	Pinky(std::string id);
	~Pinky();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;

};