#pragma once
#include "Inventory.h"
#include "Location.h"
#include "GameObject.h"
#include "Health.h"
#include <map>
#include <string>


class Player : public GameObject
{
private:
	Inventory* _inventory;
	string _locName;
	Location* _location;
	map<string, Component*>* _components;

public:
	Player(Location*, Inventory*);
	~Player();

	Inventory* getInventory();

	bool checkDirection(const string&);

	string getLocName();
	void setLocName(const string&);

	Location* getLocation();
	void setLocation(Location*);
};