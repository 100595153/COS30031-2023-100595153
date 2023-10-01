#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Item.h"

using namespace std;

class Inventory
{
private:
	vector<Item*> _items;

public:
	Inventory();
	~Inventory();

	bool find(const string&);

	void view();

	bool add(Item*);
	bool remove(const string&);

	Item* get(const string&);
};