#include "GameManager.h"

GameManager::GameManager()
{
    push_state(new MainMenu(this));
}

GameManager::~GameManager()
{
    while (!_states.empty())
        pop_state();
}

bool GameManager::running()
{
    return !_states.empty();
}

State* GameManager::current()
{
    return _states.top();
}

void GameManager::push_state(State* state)
{
    _states.push(state);
}

void GameManager::pop_state()
{
    _states.pop();
}
