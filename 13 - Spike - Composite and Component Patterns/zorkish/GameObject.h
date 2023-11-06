#pragma once
#include <string>
#include <map>
#include "Component.h"

using namespace std;

class GameObject
{
protected:
	string _name;
	string _desc;

	map<string, Component*> _components;

public:
	virtual string GetName();
	virtual string GetDesc();

	virtual Component* GetComponent(const string&);
	virtual bool AddComponent(Component*);
	virtual bool RemoveComponent(const string&);

	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual void Execute(const string&) = 0;
};