#include "Health.h"

Health::Health(int health) : _health(health)
{
	_name = "health";
}

Health::~Health()
{
}

int Health::GetHealth()
{
	return _health;
}

void Health::ModifyHealth(int modifier)
{
	_health += modifier;
}

void Health::SetHealth(int health)
{
	_health = health;
}

void Health::Update()
{
}

void Health::Render()
{
	cout << _health << " health.";
}

void Health::Execute(string)
{
}
