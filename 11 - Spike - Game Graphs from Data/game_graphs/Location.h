#pragma once
#include <string>
#include <map>
#include "Inventory.h"

using namespace std;

class Location
{
private:
	string _name;
	string _desc;

	map<string, string> _connections;//May move to /gamelocation manager at some stage.

	Inventory _inventory;
public:
	Location();
	~Location();

	string getName() const;
	string getDesc() const;

	
};