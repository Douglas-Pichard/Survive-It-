#include "assets.h"
#include "texture.h"
#include "animated_texture.h"
#include "sound.h"

#include <iostream>

Assets::Assets(SDL_Renderer* renderer)
{

	// Cache Pinky Texture.
	{
		Texture* texture = new Texture("Texture.Pinky", "Assets/pinky0.png", renderer);
		_assets[texture->id()] = texture;
	}
	// Create player walking texture.
	
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Pinky.Walking", "Assets/pinky.walking.png", renderer, 6, 200);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	//Animated Title
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Title.Background", "Assets/title.png", renderer, 2, 200);
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

	//Background texture title
	{
		Texture* texture = new Texture("Texture.Background1", "Assets/background1.png", renderer);
		_assets[texture->id()] = texture;
	}
	//Background texture game
	{
		Texture* texture = new Texture("Texture.Background2", "Assets/background2.png", renderer);
		_assets[texture->id()] = texture;
	}

	//Title Screen Texture
	{
		Texture* texture = new Texture("Texture.Place Holder", "Assets/place.holder.png", renderer);
		_assets[texture->id()] = texture;
	}

	//Lava Hazard Tile Texture
	{
		Texture* texture = new Texture("Texture.Lava", "Assets/lava.space.png", renderer);
		_assets[texture->id()] = texture;
	}

	//Spike Hazard Tile Texture
	{
		Texture* texture = new Texture("Texture.Spike", "Assets/spike.space2.png", renderer);
		_assets[texture->id()] = texture;
	}

	/*Poison Hazard Tile Texture*/
	{
		Texture* texture = new Texture("Texture.Poison", "Assets/poison.space.png", renderer);
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