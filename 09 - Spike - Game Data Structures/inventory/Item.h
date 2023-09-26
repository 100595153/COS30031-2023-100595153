#pragma once
#include <string>

using namespace std;

class Item
{
private:
	string _name;

public:
	Item(const string&);
	~Item();

	string getName() const;
};