#pragma once
#include "Command.h"

class LookCommand : public Command
{
private:

public:
	void execute(vector<string>, Player*);

	void look(Location*);

	void lookAt(Location*, string);

	void lookIn();
};