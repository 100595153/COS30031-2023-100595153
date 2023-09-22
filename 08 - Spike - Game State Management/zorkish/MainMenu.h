#pragma once
#include "GameManager.h"
#include "State.h"
#include "About.h"
#include "Help.h"
#include "LevelSelect.h"
#include "Quit.h"
#include <iostream>

class MainMenu : public State
{
public:
	MainMenu(GameManager*);
	~MainMenu();

	void update();
	void render();
};