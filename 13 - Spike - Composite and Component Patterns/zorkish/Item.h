#pragma once
#include <string>
#include <map>
#include "Component.h"

using namespace std;

class Item
{
protected:
	string _name;
	string _desc;

	map<string, Component*> _components;

public:
	Item(const string&, const string&);
	~Item();

	string getName() const;
	string getDesc() const;

	Component* GetComponent(string);
	void AddComponent(Component*);
};