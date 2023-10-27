#pragma once
#include <string>
#include "Command.h"

using namespace std;

class GoCommand : public Command
{
private:

public:
	void execute(vector<string>, Player*);
};
