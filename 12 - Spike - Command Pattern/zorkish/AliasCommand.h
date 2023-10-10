#pragma once
#include "Command.h"

class AliasCommand : public Command
{
private:

public:
	bool checkAlias(string);

	void addAlias(string);



};