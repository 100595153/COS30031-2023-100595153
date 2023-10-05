#pragma once
#include "GameManager.h"
#include "State.h"

class About : public State
{
public:
	About(GameManager*);
	~About();

	void update();
	void render();
};