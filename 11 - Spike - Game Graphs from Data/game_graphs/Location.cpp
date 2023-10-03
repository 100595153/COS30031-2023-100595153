#include "Location.h"

Location::Location(json data)
{
	//name
	_name = data["name"];

	//desc
	_desc = data["desc"];

	//connections
	for (json connection : data["connections"])
	{
		_connections.emplace(connection["direction"], connection["name"]);
	}

	_inventory = Inventory();

	//inventory
	for (json item : data["inventory"])
	{
		_inventory.add(new Item(item["name"], item["desc"]));
	}
}

Location::~Location()
{
}

string Location::getName() const
{
	return _name;
}

string Location::getDesc() const
{
	return _desc;
}

bool Location::findConnection(const string& dir)
{
	return _connections.find(dir) != _connections.end();
}

void Location::showConnections()
{
	for (auto const& con : _connections)
	{
		cout << con.first << " ";
	}
	cout << endl;
}

bool Location::findItem(const string& name)
{
	return _inventory.find(name);
}

void Location::viewItems()
{
	_inventory.view();
}

bool Location::addItem(Item* item)
{
	return _inventory.add(item);
}

bool Location::removeItem(const string& name)
{
	return _inventory.remove(name);
}

Item* Location::getItem(const string& name)
{
	return _inventory.get(name);
}
