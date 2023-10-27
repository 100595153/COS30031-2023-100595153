#include "Quit.h"

Quit::Quit(StateManager* manager)
{
	_manager = manager;
}

Quit::~Quit()
{
}

void Quit::update()
{
	processInput();

	switch (_command)
	{
	case '1':
		_manager->pop_state();
		_manager->pop_state();
		break;
	case '2':
		_manager->pop_state();
		break;
	default:
		cout << "Invalid input." << endl;
	}
}

void Quit::render()
{
	cout
		<< "Quit to desktop?" << endl
		<< endl
		<< "1. Quit" << endl
		<< "2. Back" << endl
		<< "Select 1-2:" << endl
		<< ">> ";
}
