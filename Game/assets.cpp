#include "assets.h"
#include "texture.h"
#include "animated_texture.h"
#include "sound.h"

#include <iostream>

Assets::Assets(SDL_Renderer* renderer)
{
	// Create player walking texture.
	
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Pinky.Walking", "Assets/pinky.walking.png", renderer, 6, 200);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create player running texture.
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Pinky.Running", "Assets/pinky.running.png", renderer, 6, 200);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}
	// Create player punching texture.
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Pinky.Punching", "Assets/pinky.punching.png", renderer, 6, 120);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create player idle texture.
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 50;
		Asset* player_animated_texture = new Animated_Texture("Texture.Pinky.Idle", "Assets/pinky.idle.png", renderer, 4, 300);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create player death texture.
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 50;
		Asset* player_animated_texture = new Animated_Texture("Texture.Pinky.Death", "Assets/pinky.death.png", renderer, 4, 300);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create collider texture
	{
		Texture* texture = new Texture("Texture.Collider", "Assets/collider.png", renderer);
		_assets[texture->id()] = texture;
	}

	// Create music sound
	{
		Sound* sound = new Sound("Sound.Music", "Assets/music.wav");
		_assets[sound->id()] = sound;

		Mix_PlayChannel(0, sound->data(), -1);
	}

	// Create walking sound
	{
		Sound* sound = new Sound("Sound.Walking", "Assets/walking.wav");
		_assets[sound->id()] = sound;
	}

	// Create running sound
	{
		Sound* sound = new Sound("Sound.Running", "Assets/running.wav");
		_assets[sound->id()] = sound;
	}

	// Create punching sound
	{
		Sound* sound = new Sound("Sound.Punching", "Assets/punching.wav");
		_assets[sound->id()] = sound;
	}

	// Create punching sound
	{
		Sound* sound = new Sound("Sound.Death", "Assets/death.wav");
		_assets[sound->id()] = sound;
	}

	// Create portal entry texture.
	{
		const int frame_count = 8;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* animated_texture = new Animated_Texture("Texture.Portal.Entry", "Assets/portal.green.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[animated_texture->id()] = animated_texture;
	}

	// Create portal exit texture.
	{
		const int frame_count = 8;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* animated_texture = new Animated_Texture("Texture.Portal.Exit", "Assets/portal.purple.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[animated_texture->id()] = animated_texture;
	}
	
	// Create spikes texture.
	{
		const int frame_count = 1;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* animated_texture = new Animated_Texture("Texture.Spikes.Entry", "Assets/spike.space.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[animated_texture->id()] = animated_texture;
	}
}

Assets::~Assets()
{

}

Asset* Assets::get_asset(std::string id)
{
	if(_assets.find(id) == _assets.end())
	{
		std::cout << "Attempted to find an asset that was not loaded. ID: " << id << std::endl;
		exit(1);
	}

	return _assets[id];
}