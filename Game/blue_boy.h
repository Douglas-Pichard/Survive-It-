#include "game_object.h"

class BlueBoy : public Game_Object
{
	public:
		BlueBoy(std::string id);
		~BlueBoy();

		virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets * assets, Input * input, Scene * scene) override;

};

