#include <iostream>
#include "StateManager.h"

using namespace std;

int main()
{
    StateManager* manager = new StateManager();

    while (manager->running())
    {
        manager->current()->render();
        manager->current()->update();

    }

    return 0;
}