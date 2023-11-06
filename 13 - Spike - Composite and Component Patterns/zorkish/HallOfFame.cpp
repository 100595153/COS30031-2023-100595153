#include "HallOfFame.h"

HallOfFame::HallOfFame(StateManager* manager)
{
	_manager = manager;
}

HallOfFame::~HallOfFame()
{
}

void HallOfFame::Update()
{
	processInput();

	switch (_command)
	{
	case '1':
		_manager->pop_state();
		break;
	default:
		cout << "Invalid input." << endl;
	}
}

void HallOfFame::Render()
{
	cout
		<< "High Score - Hall of Fame:" << endl
		<< endl
		<< "1. Main Menu" << endl
		<< "Select 1:" << endl
		<< ">> ";
}
