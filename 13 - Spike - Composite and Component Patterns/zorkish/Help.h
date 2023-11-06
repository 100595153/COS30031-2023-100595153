#pragma once
#include "StateManager.h"
#include "State.h"

class Help : public State
{
private:

public:
	Help(StateManager*);
	~Help();

	void Update();
	void Render();
};