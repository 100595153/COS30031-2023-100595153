#pragma once
#include "Command.h"
#include "Lock.h"

class LookCommand : public Command
{
private:

public:
	void Execute(vector<string>, Player*);

	void Look(Location*);

	void LookAt(Location*, string);

	void LookIn(string, Player*);
};