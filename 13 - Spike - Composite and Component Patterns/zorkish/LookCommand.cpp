#include "LookCommand.h"

void LookCommand::Execute(vector<string> command, Player* player)
{
	if (command.size() == 1)
	{
		Look(player->GetLocation());
	}
	else if (command.size() == 3 && command.at(1) == "at")
	{
		LookAt(player->GetLocation(), command.at(2));
	}
	else if (command.size() == 3 && command.at(1) == "in")
		LookIn(command.at(2), player);
	else
		cout << "Invalid look command." << endl;
}

void LookCommand::Look(Location* location)
{
	location->Render();
}

void LookCommand::LookAt(Location* location, string itemName)
{
	Item* item = location->GetInventory()->Get(itemName);

	if (item != nullptr)
		item->Render();
	else
		cout << "Item could not be found." << endl;
}

void LookCommand::LookIn(string itemName, Player* player)
{
	Item* item = player->GetInventory()->Get(itemName);

	if (item != nullptr)
	{
		Lock* lock = dynamic_cast<Lock*>(item->GetComponent("lock"));
		if (lock == nullptr || !lock->GetLocked())
		{
			item->GetInventory()->Render();
		}
		else
			lock->Render();
	}
	else
		cout << "Item could not be found." << endl;
}
