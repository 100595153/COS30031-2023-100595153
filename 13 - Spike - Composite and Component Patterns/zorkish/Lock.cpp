#include "Lock.h"

Lock::Lock()
{
	_name = "lock";
	_locked = true;
}

Lock::~Lock()
{
}

bool Lock::GetLocked()
{
	return _locked;
}

void Lock::ToggleLock()
{
	_locked = !_locked;
}

void Lock::Update()
{
}

void Lock::Render()
{
	switch (_locked)
	{
	case true:
		cout << "It is locked." << endl;
		break;
	case false:
		cout << "It is unlocked." << endl;
		break;
	}
}

void Lock::Execute(const string& command)
{

}
