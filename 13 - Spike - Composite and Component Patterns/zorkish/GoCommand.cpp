#include "GoCommand.h"

void GoCommand::Execute(vector<string> command, Player* player)
{
	if (command.size() == 1)
	{
		cout << "No direction specified. Please try again and provide a direction." << endl;
	}
	else if(command.size() == 2)
	{
		Location* pLoc = player->GetLocation();

		const string pCon = pLoc->GetConnection(command.at(1));

		if (pCon == "")
		{
			cout << "Invalid direction. Please choose another direction." << endl;
		}
		else
		{
			player->SetLocName(pCon);
		}
	}
	else
	{
		cout << "Unable to process command. Please input command and single direction." << endl;
	}
}
