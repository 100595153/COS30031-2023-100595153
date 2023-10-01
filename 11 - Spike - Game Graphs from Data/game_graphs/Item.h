#pragma once
#include <string>

using namespace std;

class Item
{
private:
	string _name;
	string _desc;

public:
	Item(const string&, const string&);
	~Item();

	string getName() const;
	string getDesc() const;
};