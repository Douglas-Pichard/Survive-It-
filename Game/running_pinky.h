#pragma once

#include "game_object.h"
#include "assets.h"

#include <stack>

class Pinky : public Game_Object
{
public:
	Pinky(std::string id);
	~Pinky();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
	virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config) override;

	void set_speed(float speed);
	float speed();

	enum class State
	{
		Idle,
		Walking,
		Running
	};
	void push_state(State state, Assets* assets);
	void pop_state(Assets* assets);

private:
	void handle_enter_state(State state, Assets* assets);
	void handle_exit_state(State state, Assets* assets);

	float _speed;
	std::stack<State> _state;
};