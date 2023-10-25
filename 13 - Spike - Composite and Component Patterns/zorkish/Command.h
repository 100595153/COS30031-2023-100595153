#pragma once
#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

class Command
{
protected:

public:
	virtual void execute(vector<string>, Player*) = 0;
};