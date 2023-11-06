#include "Item.h"

Item::Item(const string& name, const string& desc)
{
	_name = name;
	_desc = desc;

	_inventory = new Inventory();
}

Item::~Item() {}

Inventory* Item::GetInventory()
{
	return _inventory;
}

void Item::Update()
{
}

void Item::Render()
{
	cout << "It's a " << _name << ". " << _desc << endl;
}

void Item::Execute(const string&)
{
}
