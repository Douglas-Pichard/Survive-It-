#include "game_object.h"

class Hazard2 : public Game_Object
{
public:
	Hazard2(std::string id, std::string texture_id, Vector_2D translation, int scale);
	~Hazard2();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
};

