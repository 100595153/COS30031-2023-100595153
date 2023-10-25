#pragma once
#include <string>
#include "Location.h"
#include "Player.h"
#include "CommandManager.h"

using namespace std;
using json = nlohmann::json;

class GameWorld
{
private:
    CommandManager* _commandManager;

    bool _running;
    Player* _player;
    vector<Location*> _locations;

    vector<string> processInput();
    void movePlayer();

public:
    GameWorld(json);
    ~GameWorld();

    vector<string> splitString(string);

    Location* getLocation(string);

    bool running();

    void update();
    void render();
};