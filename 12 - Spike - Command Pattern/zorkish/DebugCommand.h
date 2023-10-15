#pragma once
#include <string>
#include "Command.h"

class DebugCommand : public Command
{
private:

public:
	void execute(vector<string>, Player*);
};