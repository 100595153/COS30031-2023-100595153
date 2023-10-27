#pragma once
#include "Component.h"
#include <map>

class GameObject
{
protected:
	string _name;
	string _desc;
	map<string, Component*> _components;

public:
	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual string GetName() = 0;
	virtual string GetDesc() = 0;

	virtual void SetName(string) = 0;
	virtual void SetDesc(string) = 0;

	virtual Component* GetComponent(string) = 0;
	virtual bool AddComponent(Component*) = 0;
	virtual bool RemoveComponent(string) = 0;
};