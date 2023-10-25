#include "InventoryCommand.h"

void InventoryCommand::execute(vector<string> command, Player* player)
{
	player->getInventory()->view();
}
