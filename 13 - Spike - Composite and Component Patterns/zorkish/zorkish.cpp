#include <iostream>
#include "StateManager.h"

using namespace std;

int main()
{
    StateManager* manager = new StateManager();

    while (manager->running())
    {
        manager->current()->Render();
        manager->current()->Update();

    }

    return 0;
}