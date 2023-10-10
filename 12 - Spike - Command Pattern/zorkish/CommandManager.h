#pragma once
#include "Command.h"
#include "AliasCommand.h"
#include "GoCommand.h"
#include "HelpCommand.h"
#include "InventoryCommand.h"
#include "LookCommand.h"
#include "DebugCommand.h"

class CommandManager
{
private:
	Player* _player;
	map<string, Command*> _commands;
public:
	CommandManager(Player*);
	~CommandManager();

	void processCommand(vector<string>);
};
