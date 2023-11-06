#pragma once
#include <string>
#include "Command.h"

class DebugCommand : public Command
{
private:

public:
	void Execute(vector<string>, Player*);
};