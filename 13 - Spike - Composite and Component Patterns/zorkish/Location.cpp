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

	_inventory = new Inventory();

	//inventory
	for (json item : data["inventory"])
	{
		_inventory->Add(new Item(item["name"], item["desc"]));
	}
}

Location::~Location()
{
}

string Location::GetConnection(const string& direction)
{
	auto iterator = _connections.find(direction);

	if (iterator == _connections.end())
		return "";
	else
		return iterator->second;
}

Inventory* Location::GetInventory()
{
	return _inventory;
}

void Location::Update()
{
}

void Location::Render()
{
	cout << "You find yourself in " << _name << "." << endl;
	cout << _desc << endl;
	
	for (pair<string, string> dir : _connections)
	{
		cout << "You see an exit to the " << dir.first << "." << endl;
	}

	_inventory->Render();
}

void Location::Execute(const string&)
{
}
