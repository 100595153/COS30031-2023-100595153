#pragma once
#include "StateManager.h"
#include "State.h"
#include "About.h"
#include "HallOfFame.h"
#include "Help.h"
#include "LevelSelect.h"
#include "Quit.h"
#include <iostream>

class MainMenu : public State
{
public:
	MainMenu(StateManager*);
	~MainMenu();

	void update();
	void render();
};