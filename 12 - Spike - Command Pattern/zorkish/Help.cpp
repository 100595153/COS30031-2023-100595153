#include "Help.h"

Help::Help(GameManager* manager)
{
	_manager = manager;
}

Help::~Help()
{
}

void Help::update()
{
	processInput();

	switch (_command)
	{
	case '1':
		_manager->pop_state();
	default:
		cout << "Invalid input." << endl;
	}
}

void Help::render()
{
	cout << endl
		<< "The following commands are supported:" << endl
		<< "quit," << endl
		<< "hiscore (Testing)" << endl
		<< endl
		<< "1. Main Menu"
		<< endl
		<< "Select 1:" << endl
		<< ">> ";
}
