#include <iostream>
#include <chrono>
#include <thread>
#include <stack>
#include "engine.h"
#include "assets.h"
#include "game_scene.h"
#include "pause_scene.h"
#include "title_screen.h"
#include "title_scene.h"
#include "input.h"
#include "editor.h"
#include "configuration.h"
#include "sound.h"


int main(void)
{
	Configuration* config = new Configuration();
	Engine* engine = new Engine("Survive It!", config);
	Assets* assets = new Assets(engine->renderer());
	Input* input = new Input();
	Editor* editor = new Editor(L"Survive It!");


	std::stack<Scene*> scenes;
	scenes.push(new Title_Scene);
	Mix_Pause(-1);
	input->get_input();

	const Uint32 milliseconds_per_seconds = 1000;
	const Uint32 frames_per_second = 60;
	const Uint32 frame_time_ms = milliseconds_per_seconds / frames_per_second;

	Uint32 frame_start_time_ms = 0;
	Uint32 frame_end_time_ms = frame_time_ms;


	while (!input->is_button_state(Input::Button::QUIT, Input::Button_State::PRESSED))
	{

		Uint32 previous_frame_duration = frame_end_time_ms - frame_start_time_ms;
		frame_start_time_ms = SDL_GetTicks();


		input->get_input();
		
		if (input->is_button_state(Input::Button::START, Input::Button_State::PRESSED))

		{
			const bool is_start = scenes.top()->id() == "Game";

			if (is_start)
			{
				Mix_Resume(-1);
				Game_Scene* game_scene = (Game_Scene*)scenes.top();
				scenes.pop();
				delete game_scene;

				
			}
			else
			{
				Mix_Resume(-1);
				scenes.push(new Game_Scene);


			}
		}
				

				scenes.top()->update(engine->window());
				input->get_input();
				editor->update(input, scenes.top(), config);
				engine->simulate(previous_frame_duration, assets, scenes.top(), input, config);


				const Uint32 current_time_ms = SDL_GetTicks();
				const Uint32 frame_duration_ms = current_time_ms - frame_start_time_ms;
				if (frame_duration_ms < frame_time_ms)
				{
					const Uint32 time_to_sleep_for = frame_time_ms - frame_duration_ms;
					std::this_thread::sleep_for(std::chrono::milliseconds(time_to_sleep_for));
				}

				frame_end_time_ms = SDL_GetTicks();
			
		}

		return 0;
	
}