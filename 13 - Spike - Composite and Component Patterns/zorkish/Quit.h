#pragma once
#include "StateManager.h"
#include "State.h"

class Quit : public State
{
private:

public:
	Quit(StateManager*);
	~Quit();

	void update();
	void render();
};