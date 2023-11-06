#include "Gameplay.h"

void Gameplay::processInput()
{
	cin >> _command;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Gameplay::Gameplay(StateManager* stateManager, string file)
{
	_stateManager = stateManager;

	ifstream input_file(file);
	json data = json::parse(input_file);
	input_file.close();

	_gameWorld = new GameWorld(data);
}

Gameplay::~Gameplay()
{
}

void Gameplay::Update()
{
	_gameWorld->Update();
}

void Gameplay::Render()
{
	_gameWorld->Render();
}
