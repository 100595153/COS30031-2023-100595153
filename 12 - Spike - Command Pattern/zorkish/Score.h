#pragma once
#include "GameManager.h"
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
	Score(GameManager*);
	~Score();
	void update();
	void render();
};