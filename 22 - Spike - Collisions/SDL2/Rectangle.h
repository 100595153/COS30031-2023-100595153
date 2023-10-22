#pragma once
#include <SDL.h>
#include "Entity.h"

class Rectangle : public Entity
{
private:
	SDL_Rect* _sprite;
	SDL_Surface* _surface;

public:
	Rectangle(string, SDL_Rect*, int, CollisionManager*);
	~Rectangle();

	SDL_Rect* GetPos();

	void Move();
	void WrapAround();

	void Update(vector<Entity*>);
	void Render(SDL_Renderer*);
};
