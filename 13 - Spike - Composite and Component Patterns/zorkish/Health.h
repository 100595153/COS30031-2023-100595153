#pragma once
#include "Component.h"

class Health : public Component
{
private:
	int _health;

public:
	Health();
	~Health();

	void Update();
	void Render();

	void Execute(const string&);
};