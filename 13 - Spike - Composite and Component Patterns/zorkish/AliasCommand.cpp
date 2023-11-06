#include "AliasCommand.h"

AliasCommand::AliasCommand(CommandManager* cm) : _commandManager(cm)
{
}

void AliasCommand::Execute(vector<string> command, Player* player)
{
    if (command.size() == 3)
        _commandManager->addCommand(command.at(1), command.at(2));
    else
        cout << "Invalid Alias Command." << endl;
}
