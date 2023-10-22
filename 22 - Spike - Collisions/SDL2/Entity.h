#pragma once
#include <iostream>
#include <vector>
#include "CollisionManager.h"

class CollisionManager;

using namespace std;

class Entity
{
protected:
	int _speed;
	SDL_Rect* _pos;

	CollisionManager* _manager;

public:
	virtual void Update(vector<Entity*>) = 0;
	virtual void Render(SDL_Renderer*) = 0;

	virtual SDL_Rect* GetPos() = 0;

	virtual void Move() = 0;
	virtual void WrapAround() = 0;
};
