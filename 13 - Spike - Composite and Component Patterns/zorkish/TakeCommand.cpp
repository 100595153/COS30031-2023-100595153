#include "TakeCommand.h"

TakeCommand::TakeCommand()
{
}

TakeCommand::~TakeCommand()
{
}

void TakeCommand::Execute(vector<string> command, Player* player)
{
	if (command.size() == 2)
		Take(command, player);
	else if (command.size() == 4 && command.at(2) == "from")
		TakeFrom(command, player);
}

void TakeCommand::Take(vector<string> command, Player* player)
{
	Inventory* playerInv = player->GetInventory();
	Inventory* locInv = player->GetLocation()->GetInventory();

	Item* item = locInv->Get(command.at(1));

	if (item != nullptr)
	{
		playerInv->Add(item);
		locInv->Remove(command.at(1));
		cout << "The " << item->GetName() << " has been added to your inventory." << endl;
	}
	else
		cout << "Item could not be found." << endl;
}

void TakeCommand::TakeFrom(vector<string> command, Player* player)
{
	Inventory* playerInv = player->GetInventory();

	Item* item = playerInv->Get(command.at(3));

	if (item != nullptr)
	{
		Inventory* itemInv = item->GetInventory();

		Item* item = itemInv->Get(command.at(1));

		if (item != nullptr)
		{
			playerInv->Add(item);
			itemInv->Remove(command.at(1));
			cout << "The " << item->GetName() << " has been taken from " << command.at(3) << "." << endl;
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
