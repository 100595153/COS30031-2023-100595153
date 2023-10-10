#pragma once
#include "Inventory.h"
#include "Location.h"


class Player
{
private:
	Inventory* _inventory;
	string _locName;
	Location* _location;
	int _health;

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