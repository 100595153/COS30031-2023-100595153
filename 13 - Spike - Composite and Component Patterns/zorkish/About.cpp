#include "About.h"

About::About(StateManager* manager)
{
	_manager = manager;
}

About::~About()
{
}

void About::Update()
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

void About::Render()
{
	cout << endl
		<< "Written by: Mitchell Wright" << endl
		<< endl
		<< "1. Main Menu"
		<< endl
		<< "Select 1:" << endl
		<< ">> ";
}
