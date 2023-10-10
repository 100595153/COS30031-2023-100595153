#pragma once
#include "State.h"
#include "MainMenu.h"
#include <stack>

using namespace std;

class StateManager
{
private:
	stack<State*> _states;
public:
	StateManager();
	~StateManager();

	bool running();
	State* current();

	void push_state(State*);
	void pop_state();
};