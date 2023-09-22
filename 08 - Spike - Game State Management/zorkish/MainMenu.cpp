#include "MainMenu.h"

MainMenu::MainMenu(GameManager* manager)
{
	_manager = manager;
}

MainMenu::~MainMenu()
{
	delete _manager;
	_manager = nullptr;
}

void MainMenu::update()
{
	processInput();

	switch (_command)
	{
	case '1':
		_manager->push_state(new LevelSelect(_manager));
		break;
	case '2':
		//_manager->push_state(new HallOfFame(_manager));
		break;
	case '3':
		_manager->push_state(new Help(_manager));
		break;
	case '4':
		_manager->push_state(new About(_manager));
		break;
	case '5':
		_manager->push_state(new Quit(_manager));
		break;
	default:
		cout << "Invalid input." << endl;
	}
}

void MainMenu::render()
{
	cout
		<< "=============================" << endl
		<< "Welcome to Zorkish Adventures" << endl
		<< "=============================" << endl
		<< endl
		<< "1. Select Adventure and Play" << endl
		<< "2. Hall of Fame" << endl
		<< "3. Help" << endl
		<< "4. About" << endl
		<< "5. Quit" << endl
		<< "Select 1-5:" << endl
		<< ">> ";
}
