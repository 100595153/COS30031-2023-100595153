#pragma once
#include "Command.h"

class InventoryCommand : public Command
{
private:

public:
	void Execute(vector<string>, Player*);
};
