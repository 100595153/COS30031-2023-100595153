#pragma once
#include "Command.h"

class InventoryCommand : public Command
{
private:

public:
	void execute(vector<string>, Player*);
};
