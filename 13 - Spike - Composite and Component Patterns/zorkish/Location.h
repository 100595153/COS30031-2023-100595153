#pragma once
#include <string>
#include <map>
#include "json.hpp"
#include "Inventory.h"

using json = nlohmann::json;
using namespace std;

class Location
{
private:
	string _name;
	string _desc;

	map<string, string> _connections;//May move to /gamelocation manager at some stage.

	Inventory _inventory;
public:
	Location(json);
	~Location();

	//Descriptors
	string getName() const;
	string getDesc() const;

	//Connections
	string findConnection(const string&);
	void showConnections();

	//Inventory interface
	bool findItem(const string&);
	void viewItems();
	bool addItem(Item*);
	bool removeItem(const string&);
	Item* getItem(const string&);
};