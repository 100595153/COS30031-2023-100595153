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

bool Inventory::Find(const string& name)
{
	for (Item* item : _items)
	{
		if (name == item->GetName())
		{
			return true;
		}
	}
	return false;
}

void Inventory::Render()
{
	if (!_items.empty())
	{
		for (Item* item : _items)
		{
			item->Render();
		}
	}
	else
		cout << "It's empty." << endl;
}

bool Inventory::Add(Item* item)
{
	if (item != nullptr && !Find(item->GetName()))
	{
		_items.push_back(item);
		return true;
	}
	return false;
}

Item* Inventory::Get(const string& name)
{
	for (Item* item : _items)
	{
		if (name == item->GetName())
			return item;
	}

	return nullptr;
}

bool Inventory::Remove(const string& name)
{
	for (auto iter = _items.begin(); iter != _items.end(); ++iter)
	{
		if ((*iter)->GetName() == name)
		{
			_items.erase(iter);
			return true;
		}
	}
	return false;
}
