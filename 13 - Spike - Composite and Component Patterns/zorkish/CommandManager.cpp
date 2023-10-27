#include "CommandManager.h"

CommandManager::CommandManager(Player* player) : _player(player)
{
	_commands.emplace("go", new GoCommand());
	_commands.emplace("look", new LookCommand());
	_commands.emplace("help", new HelpCommand(this));
	_commands.emplace("inventory", new InventoryCommand());
	_commands.emplace("alias", new AliasCommand(this));
	_commands.emplace("debug", new DebugCommand());
	//_commands.emplace("quit", new QuitCommand());
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

void CommandManager::addCommand(string aliasName, string commandName)
{
	for (auto existing : _commands)
	{
		if (existing.first == commandName)
		{
			_commands.emplace(aliasName, existing.second);
			return;
		}
	}

	cout << "Unable to add Command Alias." << endl;
}

void CommandManager::showCommands()
{
	cout << "Available Commands: " << endl;

	for (auto command : _commands)
	{
		cout << command.first << endl;
	}
}
