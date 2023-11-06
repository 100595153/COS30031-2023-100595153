#include "InventoryCommand.h"

void InventoryCommand::Execute(vector<string> command, Player* player)
{
	player->GetInventory()->Render();
}
