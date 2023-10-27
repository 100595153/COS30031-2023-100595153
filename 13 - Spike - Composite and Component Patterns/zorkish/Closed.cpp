#include "Closed.h"

Closed::Closed(bool closed) : _closed(closed)
{
	_name = "Closed";
}

Closed::~Closed()
{
}

void Closed::Update()
{
}

void Closed::Render()
{
	switch (_closed)
	{
	case true:
		cout << "closed";
	case false:
		cout << "open";
		break;
	default:
		cout << "ERROR: CLOSED COMPONENT RENDER FAILURE" << endl;
	}
}

void Closed::Execute(string command)
{
	if (command == "open")
		_closed = false;
	else if (command == "close")
		_closed = true;
	else
		cout << "This cannot be done." << endl;
}
