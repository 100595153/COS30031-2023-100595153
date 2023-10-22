#include "Circle.h"

Circle::Circle(SDL_Rect* pos, int speed, CollisionManager* manager)
{
	_pos = pos;
	_speed = speed;
	_colour = new SDL_Colour({ 0, 100, 255, 255 });

	_manager = manager;
}

Circle::~Circle()
{
	delete _pos;
	_pos = nullptr;

	delete _colour;
	_colour = nullptr;

	delete _manager;
	_manager = nullptr;
}

SDL_Rect* Circle::GetPos()
{
	return _pos;
}

void Circle::Move()
{
	_pos->x += _speed;
}

void Circle::WrapAround()
{
	if (_pos->x < 0 - _pos->w * 2) {
		_pos->x = 800 + _pos->h;
	}
	else if (_pos->x > 800 + _pos->h) {
		_pos->x = 0 - _pos->w * 2;
	}

	if (_pos->y < 0 - _pos->h * 2) {
		_pos->y = 600 + _pos->h;
	}
	else if (_pos->y > 600 + _pos->h) {
		_pos->y = 0 - _pos->h * 2;
	}
}

void Circle::Update(vector<Entity*> entities)
{
	Move();

	WrapAround();

	if (_manager->ProcessCollision(COLLISION_TYPE::Circ, this, entities))
	{
		delete _colour;
		_colour = new SDL_Colour({ 255, 0, 0, 255 });
	}
	else
	{
		delete _colour;
		_colour = new SDL_Colour({ 0, 100, 255, 255 });
	}
}

void Circle::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, _colour->r, _colour->g, _colour->b, _colour->a);
	for (int w = 0; w < _pos->h * 2; w++)
	{
		for (int h = 0; h < _pos->h * 2; h++)
		{
			int dx = _pos->h - w;
			int dy = _pos->h - h;
			if ((dx * dx + dy * dy) <= (_pos->h * _pos->h))
			{
				SDL_RenderDrawPoint(renderer, _pos->x + dx, _pos->y + dy);
			}
		}
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}
