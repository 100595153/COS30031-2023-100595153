#include "Inventory.h"

Inventory::Inventory() : _items(vector<Item*>()) {}

Inventory::~Inventory()
{
	for (Item* item : _items)
	{
		delete item;
		item = nullptr;
	}

	_items.clear();
}

bool Inventory::find(const string& name)
{
	for (Item* item : _items)
	{
		if (name == item->getName())
		{
			return true;
		}
	}
	return false;
}

void Inventory::view()
{
	for (Item* item : _items)
		cout << item->getName() << endl;
}

bool Inventory::add(Item* item)
{
	if (item != nullptr && !find(item->getName()))
	{
		_items.push_back(item);
		return true;
	}
	return false;
}

Item* Inventory::get(const string& name)
{
	for (Item* item : _items)
	{
		if (name == item->getName())
			return item;
	}

	return new Item("Error", "Invalid item.");
}

bool Inventory::remove(const string& name)
{
	for (auto iter = _items.begin(); iter != _items.end(); ++iter)
	{
		if ((*iter)->getName() == name)
		{
			_items.erase(iter);
			return true;
		}
	}
	return false;
}
