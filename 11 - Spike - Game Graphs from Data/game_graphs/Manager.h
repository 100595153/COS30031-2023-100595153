#pragma once
#include <string>
#include "Location.h"

using namespace std;

class Manager
{
private:
    bool _running;
    Location* _currentLocation;
    vector<Location*> _locations;

    vector<string> splitString(string);
    vector<string> processInput();

    void move(const string&);

public:
    Manager(vector<Location*>);
    ~Manager();

    bool running();

    void update();
    void render();
};