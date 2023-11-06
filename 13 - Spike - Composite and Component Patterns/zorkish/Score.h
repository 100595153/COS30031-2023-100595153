#pragma once
#include "StateManager.h"
#include "State.h"
#include "Quit.h"
#include "Score.h"
#include <iostream>

class Score : public State
{
private:
	string _command;

	void processInput();
public:
	Score(StateManager*);
	~Score();
	void Update();
	void Render();
};