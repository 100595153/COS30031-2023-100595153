#include <iostream>
#include "Grid.h"

using namespace std;

int main()
{
    Grid *world = new Grid();
    char input = ' ';


    cout << "Welcome to GridWorld: Quantised Excitement. Fate is waiting for you!\n";

    while (input != 'q')
    {
        world->Update();

        world->Render();
    }

    cout << endl << "Thanks for playing!" << endl;
}