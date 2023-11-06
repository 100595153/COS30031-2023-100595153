#pragma once
#include <string>
#include <iostream>
#include "GameObject.h"
#include "Inventory.h"

using namespace std;

class Inventory;

class Item : public GameObject
{
private:
	Inventory* _inventory;

public:
	Item(const string&, const string&);
	~Item();

	Inventory* GetInventory();

	void Update();
	void Render();
	void Execute(const string&);
};