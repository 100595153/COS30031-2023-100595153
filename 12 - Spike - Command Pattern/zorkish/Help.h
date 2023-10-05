#pragma once
#include "GameManager.h"
#include "State.h"

class Help : public State
{
private:

public:
	Help(GameManager*);
	~Help();

	void update();
	void render();
};