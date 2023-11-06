#pragma once
#include "StateManager.h"
#include "State.h"
#include "Gameplay.h"
#include <iostream>

class LevelSelect : public State
{
public:
	LevelSelect(StateManager*);
	~LevelSelect();

	void Update();
	void Render();
};