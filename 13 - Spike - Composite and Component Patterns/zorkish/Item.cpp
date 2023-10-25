#include "Item.h"

Item::Item(const string& name, const string& desc) : _name(name), _desc(desc) {}

Item::~Item() {}

string Item::getName() const
{
	return _name;
}

string Item::getDesc() const
{
	return _desc;
}