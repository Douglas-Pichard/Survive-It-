#include "game_object.h"
class Hazard : public Game_Object
{
public:
	Hazard(std::string id);
	~Hazard();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
};