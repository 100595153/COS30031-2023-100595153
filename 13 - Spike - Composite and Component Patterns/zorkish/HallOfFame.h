#pragma once
#include "StateManager.h"
#include "State.h"
#include <iostream>

class HallOfFame : public State
{
public:
	HallOfFame(StateManager*);
	~HallOfFame();

	void Update();
	void Render();
};