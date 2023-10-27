#pragma once
#include "Component.h"

class Health : public Component
{
private:
	int _health;

public:
	Health(int);
	~Health();

	int GetHealth();
	void ModifyHealth(int);
	void SetHealth(int);

	void Update();
	void Render();

	void Execute(string);
};