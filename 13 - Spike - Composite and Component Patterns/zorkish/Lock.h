#pragma once
#include "Component.h"

class Lock : public Component
{
private:
	bool _locked;

public:
	Lock();
	~Lock();

	bool GetLocked();
	void ToggleLock();
	
	void Update();
	void Render();

	void Execute(const string&);
};