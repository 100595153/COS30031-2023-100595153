#pragma once
#include "Command.h"

class TakeCommand : public Command
{
private:

public:
	TakeCommand();
	~TakeCommand();

	void Execute(vector<string>, Player*);

	void Take(vector<string>, Player*);
	void TakeFrom(vector<string>, Player*);
};