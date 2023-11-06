#include "GameWorld.h"

GameWorld::GameWorld(json data) : _running(true)
{
	for (json loc : data["locations"])
	{
		_locations.push_back(new Location(loc));
	}

	Inventory* inv = new Inventory();

	_player = new Player(_locations.front(), inv);

	_commandManager = new CommandManager(_player);

	cout << "Welcome to Zorkish Adventure" << endl;
}

GameWorld::~GameWorld() {} //TODO

Location* GameWorld::GetLocation(string locName)
{
	for (Location* loc : _locations)
	{
		if (loc->GetName() == locName)
			return loc;
	}

	return NULL;
}

vector<string> GameWorld::SplitString(string input)
{
	vector<string> result;

	size_t pos = 0;
	string token;
	string delimiter = " ";
	while ((pos = input.find(delimiter)) != string::npos) {
		token = input.substr(0, pos);
		result.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	result.push_back(input);

	return result;
}

vector<string> GameWorld::processInput()
{
	string input;
	vector<string> commands;

	getline(cin, input);

	return SplitString(input);
}

void GameWorld::movePlayer()
{
	_player->SetLocation(GetLocation(_player->GetLocName()));
}

bool GameWorld::Running()
{
	return _running;
}

void GameWorld::Update()
{
	_commandManager->processCommand(processInput());
	movePlayer();
}

void GameWorld::Render()
{
	_player->Render();
}
