#include "StateManager.h"

StateManager::StateManager()
{
    push_state(new MainMenu(this));
}

StateManager::~StateManager()
{
    while (!_states.empty())
        pop_state();
}

bool StateManager::running()
{
    return !_states.empty();
}

State* StateManager::current()
{
    return _states.top();
}

void StateManager::push_state(State* state)
{
    _states.push(state);
}

void StateManager::pop_state()
{
    _states.pop();
}
