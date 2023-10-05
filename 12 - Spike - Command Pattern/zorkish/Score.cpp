#include "Score.h"

void Score::processInput()
{
	cin >> _command;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Score::Score(GameManager* manager)
{
	_manager = manager;
}

Score::~Score()
{
}

void Score::update()
{
	processInput();

	_manager->pop_state();
	_manager->push_state(new HallOfFame(_manager));
}

void Score::render()
{
	cout
		<< "-----------------" << endl
		<< "Score" << endl
		<< endl
		<< "Enter your name:" << endl
		<< ">> ";
}
