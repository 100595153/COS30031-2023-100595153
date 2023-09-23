#include "LevelSelect.h"

LevelSelect::LevelSelect(GameManager* manager)
{
	_manager = manager;
}

LevelSelect::~LevelSelect()
{
}

void LevelSelect::update()
{
	processInput();

	switch (_command)
	{
	case '1':
	case '2':
	case '3':
		_manager->pop_state();
		_manager->push_state(new Gameplay(_manager));
		break;
	default:
		cout << "Invalid input." << endl;
	}
}

void LevelSelect::render()
{
	cout
		<< "Select Adventure:" << endl
		<< endl
		<< "1. The Placeholder and the World" << endl
		<< "2. 2 Placeholder 2 World" << endl
		<< "3. Placeholder and the World 3: Pseudo-code Drift" << endl
		<< "Select 1-3:" << endl
		<< ">> ";
}
