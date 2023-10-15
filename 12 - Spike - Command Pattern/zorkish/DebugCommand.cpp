#include "DebugCommand.h"

void DebugCommand::execute(vector<string> command, Player* player)
{
	cout
		<< "===DEBUG INFORMATION===" << endl
		<< "---PLAYER INFO---" << endl
		<< "Player Health: " << player->getHealth() << endl
		<< "Items Held: " << endl;
	player->getInventory()->view();
	cout
		<< "---LOCATION INFORMATION---" << endl
		<< "Location Name: " << player->getLocation()->getName() << endl
		<< "Location Desc: " << player->getLocation()->getDesc() << endl
		<< "Location Connections: " << endl;
	player->getLocation()->showConnections();
}
