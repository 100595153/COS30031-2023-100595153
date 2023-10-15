#include "Player.h"

Player::Player(Location* loc, Inventory* inv) : _location(loc), _inventory(inv), _health(100)
{
	_locName = _location->getName();

	_inventory->add(new Item("shovel", "DIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIG"));
}

Player::~Player()
{
	delete _location;
	delete _inventory;


	_location = nullptr;
	_inventory = nullptr;
}

int Player::getHealth()
{
	return _health;
}

void Player::takeDamage(int damage)
{
	_health -= damage;
}

Inventory* Player::getInventory()
{
	return _inventory;
}

bool Player::checkDirection(const string& dir)
{
	return _location->findConnection(dir) == "";
}

Location* Player::getLocation()
{
	return _location;
}

string Player::getLocName()
{
	return _locName;
}

void Player::setLocName(const string& locName)
{
	_locName = locName;
}

void Player::setLocation(Location* loc)
{
	_location = loc;
}
