#pragma once
#include "StateManager.h"
#include <iostream>

using namespace std;

class StateManager;

class State
{
protected:
	StateManager* _manager = nullptr;
	char _command;

	virtual void processInput()
	{
		cin >> _command;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	};

public:
	virtual void Update() = 0;
	virtual void Render() = 0;
};