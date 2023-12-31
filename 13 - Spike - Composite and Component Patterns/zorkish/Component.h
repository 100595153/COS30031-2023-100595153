#pragma once
#include <string>
#include <iostream>

using namespace std;

class Component
{
protected:
	string _name;

public:
	virtual string GetName() const;

	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual void Execute(const string&) = 0;
};