#include "Manager.h"

Manager::Manager(vector<Location*> locations) : _running(true), _locations(locations)
{
	_currentLocation = _locations.at(0);
}

Manager::~Manager() {}

vector<string> Manager::splitString(string input)
{
	vector<string> result;

	size_t pos = 0;
	string token;
	string delimiter = " ";
	while ((pos = input.find(delimiter)) != string::npos) {
		token = input.substr(0, pos);
		result.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	result.push_back(input);

	return result;
}

vector<string> Manager::processInput()
{
	string input;
	getline(cin, input);

	return splitString(input);
}

void Manager::move(const string& name)
{
	for (Location* loc : _locations)
	{
		if (loc->getName() == name)
		{
			_currentLocation = loc;
			return;
		}
	}
	cout << "I can't do that, Dave." << endl;
}

bool Manager::running()
{
	return _running;
}

void Manager::update()
{
	vector<string> input = processInput();

	if (!input.empty() && input.front() == "quit")
	{
		_running = false;
	}
	else if (input.size() > 1 && input.front() == "go")
	{
		move(_currentLocation->findConnection(input.at(1)));
	}
	else
		cout << "Invalid input." << endl;
}

void Manager::render()
{
	cout
		<< "You are at " << _currentLocation->getName() << "." << endl
		<< _currentLocation->getDesc() << endl
		<< ">> ";
}
