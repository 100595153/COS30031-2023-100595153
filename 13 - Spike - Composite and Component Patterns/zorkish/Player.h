#pragma once
#include "GameObject.h"
#include "Location.h"
#include "Inventory.h"

class Player : public GameObject
{
private:
	Inventory* _inventory;

	string _locName;
	Location* _location;

public:
	Player(Location*, Inventory*);
	~Player();

	bool CheckDirection(const string&);

	string GetLocName();
	void SetLocName(const string&);

	Location* GetLocation();
	void SetLocation(Location*);

	Inventory* GetInventory();

	void Update();
	void Render();

	void Execute(const string&);
};