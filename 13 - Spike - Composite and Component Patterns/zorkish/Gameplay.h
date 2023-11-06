#pragma once
#include "StateManager.h"
#include "GameWorld.h"
#include "State.h"
#include "Quit.h"
#include "Score.h"
#include <iostream>
#include <fstream>

using namespace std;
using json = nlohmann::json;

class Gameplay : public State
{
private:
	string _command;

	StateManager* _stateManager;
	GameWorld* _gameWorld;

	void processInput();
public:
	Gameplay(StateManager*, string);
	~Gameplay();
	void Update();
	void Render();
};