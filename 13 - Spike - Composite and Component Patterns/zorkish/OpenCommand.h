#pragma once
#include "Command.h"
#include "Lock.h"

class OpenCommand : public Command
{
	void Execute(vector<string>, Player*);
};