#pragma once
#include <SDL.h>
#include "Entity.h"

class Entity;

enum COLLISION_TYPE
{
	Circ,
	Box,
	Default
};

using namespace std;

class CollisionManager
{
private:

public:
	CollisionManager();
	~CollisionManager();

	bool ProcessCollision(COLLISION_TYPE, Entity*, vector<Entity*>);

	bool BoxCollision(Entity*, vector<Entity*>);
	bool CircleCollision(Entity*, vector<Entity*>);

};