#pragma once
#include <string>
#include <map>
#include "json.hpp"
#include "Inventory.h"

using json = nlohmann::json;
using namespace std;

class Location : public GameObject
{
private:
	Inventory* _inventory;

	map<string, Component*> _components;
	map<string, string> _connections;

public:
	Location(json);
	~Location();

	string GetConnection(const string&);
	Inventory* GetInventory();

	void Update();
	void Render();

	void Execute(const string&);
};