#pragma once
#include "Location.h"
#include "Component.h"

class CurrentLocation : public Component
{
private:
	string _name;
	Location* location;

public:
	CurrentLocation(Location*);
	~CurrentLocation();

	string GetName();
	void SetName(const string&);
	
	Location* GetLocation();
	void SetLocation(Location*);
};
