#include <iostream>
#include "Grid.h"

using namespace std;

int main()
{
    Grid *world = new Grid();

    cout << "Welcome to Grid World: Griddy, Set, Go" << endl;

    world->Render();

    while (world->IsRunning())
    {
        world->Update();

        world->Render();
    }

    cout << endl << "Thanks for playing!" << endl;

    return 0;
}