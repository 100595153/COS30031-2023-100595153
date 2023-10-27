#include "LookCommand.h"

void LookCommand::execute(vector<string> command, Player* player)
{
	if (command.size() == 1)
	{
		look(player->getLocation());
	}
	else if (command.size() == 3 && command.at(1) == "at")
	{
		lookAt(player->getLocation(), command.at(2));
	}
	else if (command.size() == 4 && command.at(1) == "at" && command.at(3) == "in")
	{

	}
	else
		cout << "Invalid look command." << endl;
}

void LookCommand::look(Location* location)
{
	cout 
		<< "You take in your surroundings." << endl
		<< "You are in " << location->getName() << ". "
		<< location->getDesc() << endl;
}

void LookCommand::lookAt(Location* location, string itemName)
{
	cout << location->getItem(itemName)->getDesc() << endl;
}

void LookCommand::lookIn()
{

}
