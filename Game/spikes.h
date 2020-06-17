#include "game_object.h"

class Spikes : public Game_Object
{
public:
	Spikes(std::string id);
	~Spikes();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;

};

