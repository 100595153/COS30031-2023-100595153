#include <iostream>
#include "GameManager.h"

using namespace std;

int main()
{
    GameManager* manager = new GameManager();

    while (manager->running())
    {
        manager->current()->render();
        manager->current()->update();

    }

    return 0;
}