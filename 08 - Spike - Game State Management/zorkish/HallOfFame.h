#pragma once
#include "GameManager.h"
#include "State.h"
#include <iostream>

class HallOfFame : public State
{
public:
	HallOfFame(GameManager*);
	~HallOfFame();

	void update();
	void render();
};