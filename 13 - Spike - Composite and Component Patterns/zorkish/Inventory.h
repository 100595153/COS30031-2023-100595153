#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Item.h"

using namespace std;

class Item;

class Inventory
{
private:
	vector<Item*> _items;

public:
	Inventory();
	~Inventory();

	bool Find(const string&);

	void Render();

	bool Add(Item*);
	bool Remove(const string&);

	Item* Get(const string&);
};