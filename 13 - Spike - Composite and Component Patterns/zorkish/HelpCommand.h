#pragma once
#include "Command.h"
#include "CommandManager.h"

class CommandManager;

class HelpCommand : public Command
{
private:
	CommandManager* _commandManager;
public:
	HelpCommand(CommandManager*);

	void Execute(vector<string>, Player*);
};
