#pragma once

#include <SFML/Graphics.hpp>
#include "ResourceCache.h"

class Scene
{
public:
	Scene();
	virtual ~Scene() = 0;

	virtual void Update() = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void NotifySwitchedTo();
};