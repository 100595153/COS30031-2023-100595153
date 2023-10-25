#pragma once
#include <string>
#include <iostream>

using namespace std;

class Component
{
protected:
	string _name;

public:
	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual void Execute(string) = 0;
};