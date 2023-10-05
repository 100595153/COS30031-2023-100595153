#pragma once
#include "GameManager.h"
#include "State.h"
#include "Quit.h"
#include "Score.h"
#include <iostream>

class Gameplay : public State
{
private:
	string _command;

	void processInput();
public:
	Gameplay(GameManager*);
	~Gameplay();
	void update();
	void render();
};