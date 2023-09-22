#pragma once
#include "GameManager.h"
#include "State.h"

class Quit : public State
{
private:

public:
	Quit(GameManager*);
	~Quit();

	void update();
	void render();
};