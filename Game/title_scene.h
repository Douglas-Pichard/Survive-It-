#pragma once
#include "title_scene.h"
#include "scene.h"

class Title_Scene : public Scene
{
public:
	Title_Scene();
	~Title_Scene();

	virtual void update(SDL_Window* window) override;
};

