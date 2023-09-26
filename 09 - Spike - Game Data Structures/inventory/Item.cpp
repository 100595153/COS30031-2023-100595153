#include "Item.h"

Item::Item(const string& name) : _name(name) {}

Item::~Item() {}

string Item::getName() const
{
	return _name;
}
