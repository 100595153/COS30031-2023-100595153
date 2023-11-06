#include "OpenCommand.h"

void OpenCommand::Execute(vector<string> command, Player* player)
{
	if (command.size() == 2)
	{
		Item* item = player->GetInventory()->Get(command.at(1));

		if (item != nullptr)
		{
			Lock* lock = dynamic_cast<Lock*>(item->GetComponent("lock"));
			if (lock != nullptr)
			{
				lock->ToggleLock();
				lock->Render();
			}
			else
				cout << "There is no lock to open." << endl;
		}
		else
			cout << "Item could not be found." << endl;
	}
}
