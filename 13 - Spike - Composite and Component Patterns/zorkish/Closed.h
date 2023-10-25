#pragma once
#include "Component.h"

class Closed : public Component
{
private:
	bool _closed;

public:
	Closed(bool);
	~Closed();

	void Update();
	void Render();

	void Execute(string);
};