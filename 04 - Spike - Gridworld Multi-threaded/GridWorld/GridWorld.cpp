#include <iostream>
#include <thread>
#include "Grid.h"

using namespace std;

void update()
{
    cout << "Update" << endl;
}

void render()
{
    cout << "Render" << endl;
}

int main()
{
    Grid* world = new Grid();

    thread t1(update);
    thread t2(render);

    int freq = 60;

    cout << "Welcome to Grid World: Griddy, Set, Go" << endl;

    world->Render();

    //long timelastcall = timeGetTime();
    while (world->IsRunning())
    {
        if(true)
            t1.join();
        t2.join();
    }

    cout << endl << "Thanks for playing!" << endl;
}