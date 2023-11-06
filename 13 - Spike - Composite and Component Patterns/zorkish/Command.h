#pragma once
#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

class Command
{
protected:

public:
	virtual void Execute(vector<string>, Player*) = 0;
};