#pragma once
#include "StateManager.h"
#include "State.h"

class About : public State
{
public:
	About(StateManager*);
	~About();

	void update();
	void render();
};