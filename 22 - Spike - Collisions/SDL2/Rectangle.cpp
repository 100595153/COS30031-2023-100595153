#include "Rectangle.h"

Rectangle::Rectangle(string fileName, SDL_Rect* pos, int speed, CollisionManager* manager)
{
	_pos = pos;
	_speed = speed;

	_sprite = new SDL_Rect({0, 0, 100, 100});

	_surface = SDL_LoadBMP(fileName.c_str());

	_manager = manager;
}

Rectangle::~Rectangle()
{
	delete _pos;
	delete _surface;
	delete _manager;

	_pos = nullptr;
	_surface = nullptr;
	_manager = nullptr;
}

SDL_Rect* Rectangle::GetPos()
{
	return _pos;
}

void Rectangle::Move()
{
	_pos->x += _speed;
}

void Rectangle::WrapAround()
{
	if (_pos->x < 0 - _pos->w) {
		_pos->x = 800;  // Wrap to the right edge
	}
	else if (_pos->x > 800) {
		_pos->x = 0 - _pos->w;    // Wrap to the left edge
	}

	if (_pos->y < 0 - _pos->h) {
		_pos->y = 600;  // Wrap to the bottom edge
	}
	else if (_pos->y > 600) {
		_pos->y = 0 - _pos->h;    // Wrap to the top edge
	}
}

void Rectangle::Update(vector<Entity*> entities)
{
	Move();

	WrapAround();

	if (_manager->ProcessCollision(COLLISION_TYPE::Box, this, entities))
		_sprite->x = 100;
	else
		_sprite->x = 0;
}

void Rectangle::Render(SDL_Renderer* renderer)
{
	SDL_Texture* rectTexture = SDL_CreateTextureFromSurface(renderer, _surface);

	SDL_RenderCopy(renderer, rectTexture, _sprite, _pos);
}
