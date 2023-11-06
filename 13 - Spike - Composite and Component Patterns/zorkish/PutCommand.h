#pragma once
#include "Command.h"

class PutCommand : public Command
{
private:

public:
	PutCommand();
	~PutCommand();

	void Execute(vector<string>, Player*);

	void Put(vector<string>, Player*);
	void PutIn(vector<string>, Player*);
};