#pragma once

class DebugCommand : public Command
{
private:

public:
	DebugCommand();
	~DebugCommand();

	void execute(vector<string>, Player*);
};