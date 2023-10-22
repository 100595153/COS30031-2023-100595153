#pragma once
#include <SDL.h>
#include "Entity.h"

class Circle : public Entity
{
private:
	SDL_Colour* _colour;

public:
	Circle(SDL_Rect*, int, CollisionManager*);
	~Circle();

	SDL_Rect* GetPos();

	void Move();
	void WrapAround();

	void Update(vector<Entity*>);
	void Render(SDL_Renderer*);
};