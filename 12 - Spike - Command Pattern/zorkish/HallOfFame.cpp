#include "HallOfFame.h"

HallOfFame::HallOfFame(GameManager* manager)
{
	_manager = manager;
}

HallOfFame::~HallOfFame()
{
}

void HallOfFame::update()
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

void HallOfFame::render()
{
	cout
		<< "High Score - Hall of Fame:" << endl
		<< endl
		<< "1. Main Menu" << endl
		<< "Select 1:" << endl
		<< ">> ";
}
