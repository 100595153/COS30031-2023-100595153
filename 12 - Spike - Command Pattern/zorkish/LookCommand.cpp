#include "LookCommand.h"

void LookCommand::execute(vector<string> command, Player* player)
{
	if (command.size() == 1)
	{
		look(player->getLocation());
	}
	else if (command.at(1) == "at" && command.size() == 3)
	{
		lookAt(player->getLocation(), command.at(2));
	}
	else
		cout << "Invalid look command." << endl;
}

void LookCommand::look(Location* location)
{
	cout << location->getDesc() << endl;
}

void LookCommand::lookAt(Location* location, string itemName)
{
	cout << location->getItem(itemName)->getDesc() << endl;
}
