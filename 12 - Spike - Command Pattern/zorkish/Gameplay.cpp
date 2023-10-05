#include "Gameplay.h"

void Gameplay::processInput()
{
	cin >> _command;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Gameplay::Gameplay(GameManager* manager)
{
	_manager = manager;
}

Gameplay::~Gameplay()
{
}

void Gameplay::update()
{
	processInput();

	if (_command == "quit")
	{
		_manager->pop_state();
	}
	else if (_command == "hiscore")
	{
		_manager->pop_state();
		_manager->push_state(new Score(_manager));
	}
	else
		cout << "Invalid input." << endl;
}

void Gameplay::render()
{
	cout
		<< "------------------------" << endl
		<< "This game is in early access." << endl
		<< "To continue playing, please donate $199.99 to the following PayPal address" << endl
		<< "acmetonto@hotmail.com" << endl
		<< ">> ";
}
