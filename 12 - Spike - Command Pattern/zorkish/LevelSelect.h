#pragma once
#include "GameManager.h"
#include "State.h"
#include "Gameplay.h"
#include <iostream>

class LevelSelect : public State
{
public:
	LevelSelect(GameManager*);
	~LevelSelect();

	void update();
	void render();
};