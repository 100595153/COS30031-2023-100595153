#include "HelpCommand.h"

HelpCommand::HelpCommand(CommandManager* cm) : _commandManager(cm)
{
}

void HelpCommand::execute(vector<string>, Player*)
{
	_commandManager->showCommands();
}
