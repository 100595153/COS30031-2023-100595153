#include "CommandManager.h"

CommandManager::CommandManager(Player* player) : _player(player)
{
	_commands.emplace("go", new GoCommand());
	//_commands.emplace("look", new LookCommand());
	//_commands.emplace("look", new HelpCommand());
	//_commands.emplace("look", new InventoryCommand());
	//_commands.emplace("look", new AliasCommand());
	//_commands.emplace("look", new DebugCommand());
}

CommandManager::~CommandManager()
{
}

void CommandManager::processCommand(vector<string> command)
{
	if (_commands.find(command.at(0)) != _commands.end())
	{
		_commands.at(command.at(0))->execute(command, _player);
	}
	else
		cout << "Invalid command." << endl;
}
