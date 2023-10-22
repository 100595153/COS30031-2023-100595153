#include "CollisionManager.h"

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

bool CollisionManager::ProcessCollision(COLLISION_TYPE type, Entity* e1, vector<Entity*> entities)
{
	switch (type)
	{
	case Box:
		return BoxCollision(e1, entities);
		break;
	case Circ:
		return CircleCollision(e1, entities);
		break;
	case Default:
	default:
		clog << "Error with Collision Type." << endl;
		return false;
		break;
	}
}

bool CollisionManager::BoxCollision(Entity* e1, vector<Entity*> entities)
{
	for (Entity* e2 : entities)
	{
		if (e1 != e2 && SDL_HasIntersection(e1->GetPos(), e2->GetPos()))
			return true;
	}
	return false;
}

bool CollisionManager::CircleCollision(Entity* e1, vector<Entity*> entities)
{
	for (Entity* e2 : entities)
	{
		if (e1 != e2 && (pow(e2->GetPos()->x - e1->GetPos()->x, 2) + pow(e2->GetPos()->y - e1->GetPos()->y, 2)) < pow((e1->GetPos()->h + e2->GetPos()->h), 2))
			return true;
	}
	return false;
}
