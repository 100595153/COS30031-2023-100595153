#include "Player.h"
#include "Lock.h"

Player::Player(Location* loc, Inventory* inv)
{
	_inventory = inv;
	_location = loc;
	_locName = _location->GetName();

	Item* item = new Item("bag", "oh no");
	item->AddComponent(new Lock());
	_inventory->Add(item);
}

Player::~Player()
{
	delete _location;
	delete _inventory;


	_location = nullptr;
	_inventory = nullptr;
}

bool Player::CheckDirection(const string& dir)
{
	return _location->GetConnection(dir) == "";
}

Location* Player::GetLocation()
{
	return _location;
}

string Player::GetLocName()
{
	return _locName;
}

void Player::SetLocName(const string& locName)
{
	_locName = locName;
}

void Player::SetLocation(Location* loc)
{
	_location = loc;
}

Inventory* Player::GetInventory()
{
	return _inventory;
}

void Player::Update()
{
}

void Player::Render()
{
	cout << "You're in " << _location->GetName() << ". " 
		<< "What will you do?" << endl;
}

void Player::Execute(const string&)
{
}
