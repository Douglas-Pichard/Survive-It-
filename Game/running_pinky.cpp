#pragma once

#include "running_pinky.h"
#include "sound.h"

#include <iostream>

#include <SDL_mixer.h>

Pinky::Pinky(std::string id)
	: Game_Object(id, "Texture.Pinky.Walking")
{
	_speed = 0.1f;

	_translation = Vector_2D(0, 0);

	_collider.set_radius(_width / 5.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));

	_state.push(State::Idle);
}
Pinky::~Pinky()
{
}

void Pinky::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config);
}

void Pinky::simulate_AI(Uint32, Assets* assets, Input* input, Scene*)
{
	switch (_state.top())
	{
	case State::Idle:
		if (input->is_button_state(Input::Button::RUNNING, Input::Button_State::DOWN) && _velocity.magnitude() > 0.0f)
		{
			push_state(State::Running, assets);
		}
		else if (_velocity.magnitude() > 0.0f)
		{
			push_state(State::Walking, assets);
		}
		break;
	case State::Walking:
		if (_velocity.magnitude() == 0.0f)
		{
			pop_state(assets);
		}
		else if (input->is_button_state(Input::Button::RUNNING, Input::Button_State::PRESSED))
		{
			push_state(State::Running, assets);
		}
		break;
	case State::Running:
		if (_velocity.magnitude() == 0.0f)
		{
			pop_state(assets);
		}
		else if (input->is_button_state(Input::Button::RUNNING, Input::Button_State::RELEASED))
		{
			pop_state(assets);
		}
		break;
	}

	_velocity = Vector_2D(0, 0);

	if (input->is_button_state(Input::Button::RIGHT, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(1.0f, 0);
	}

	if (input->is_button_state(Input::Button::LEFT, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(-1.0f, 0);
	}

	if (input->is_button_state(Input::Button::UP, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(0, -1.0f);
	}

	if (input->is_button_state(Input::Button::DOWN, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(0, 1.0f);
	}

	_velocity.normalize();
	_velocity.scale(_speed);
}

void Pinky::set_speed(float speed)
{
	_speed = speed;
}
float Pinky::speed()
{
	return _speed;
}

void Pinky::push_state(State state, Assets* assets)
{
	handle_exit_state(_state.top(), assets);

	_state.push(state);
	handle_enter_state(_state.top(), assets);
}
void Pinky::pop_state(Assets* assets)
{
	handle_exit_state(_state.top(), assets);

	_state.pop();
	handle_enter_state(_state.top(), assets);
}

void Pinky::handle_enter_state(State state, Assets* assets)
{
	switch (state)
	{
	case State::Idle:
		_texture_id = "Texture.Pinky.Idle";
		break;
	case State::Walking:
	{
		_texture_id = "Texture.Pinky.Walking";
		_speed = 0.15f;
		const int walking_channel = 1;
		Sound* sound = (Sound*)assets->get_asset("Sound.Walking");
		Mix_PlayChannel(walking_channel, sound->data(), -1);
		break;
	}
	case State::Running:
	{
		_texture_id = "Texture.Pinky.Running";
		_speed = 0.3f;
		const int running_channel = 2;
		Sound* sound = (Sound*)assets->get_asset("Sound.Running");
		Mix_PlayChannel(running_channel, sound->data(), -1);
		break;
	}
	}
}

void Pinky::handle_exit_state(State state, Assets*)
{
	switch (state)
	{
	case State::Idle:
		break;
	case State::Walking:
	{
		const int walking_channel = 1;
		Mix_HaltChannel(walking_channel);
		break;
	}
	case State::Running:
	{
		const int running_channel = 2;
		Mix_HaltChannel(running_channel);
		break;
	}
	}
}