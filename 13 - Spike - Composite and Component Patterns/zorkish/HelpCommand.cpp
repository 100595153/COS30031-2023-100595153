#include "HelpCommand.h"

HelpCommand::HelpCommand(CommandManager* cm) : _commandManager(cm)
{
}

void HelpCommand::Execute(vector<string>, Player*)
{
	_commandManager->showCommands();
}
