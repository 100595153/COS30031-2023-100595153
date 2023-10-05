#pragma once
#include "State.h"
#include "MainMenu.h"
#include <stack>

using namespace std;

class GameManager
{
private:
	stack<State*> _states;
public:
	GameManager();
	~GameManager();

	bool running();
	State* current();

	void push_state(State*);
	void pop_state();
};