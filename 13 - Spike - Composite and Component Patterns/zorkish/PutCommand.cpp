#include "PutCommand.h"

PutCommand::PutCommand()
{
}

PutCommand::~PutCommand()
{
}

void PutCommand::Execute(vector<string> command, Player* player)
{
	if (command.size() == 2)
		Put(command, player);
	else if (command.size() == 4 && command.at(2) == "in")
		PutIn(command, player);
}

void PutCommand::Put(vector<string> command, Player* player)
{
	Inventory* playerInv = player->GetInventory();
	Inventory* locInv = player->GetLocation()->GetInventory();

	Item* item = playerInv->Get(command.at(1));

	if (item != nullptr)
	{
		locInv->Add(item);
		playerInv->Remove(command.at(1));
		cout << "The " << item->GetName() << " has been dropped from your inventory." << endl;
	}
	else
		cout << "Item could not be found." << endl;
}

void PutCommand::PutIn(vector<string> command, Player* player)
{
	//PUT GUN IN SWORD
	Inventory* playerInv = player->GetInventory();
	Item* item = playerInv->Get(command.at(3));

	if (item != nullptr)
	{
		Inventory* itemInv = item->GetInventory();

		item = playerInv->Get(command.at(1));

		if (item != nullptr)
		{
			itemInv->Add(item);
			playerInv->Remove(command.at(1));
			cout << "The " << item->GetName() << " has been added to the " << command.at(3) << "." << endl;
		}
		else
			cout << "Item could not be found." << endl;
	}
	else
	{
		cout << "Item not found." << endl;
		return;
	}
}
