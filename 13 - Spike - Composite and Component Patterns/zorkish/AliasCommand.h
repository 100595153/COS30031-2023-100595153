#pragma once
#include "Command.h"
#include "CommandManager.h"

class CommandManager;

class AliasCommand : public Command
{
private:
	CommandManager* _commandManager;
public:
	AliasCommand(CommandManager*);
	~AliasCommand();

	void execute(vector<string>, Player*);
};