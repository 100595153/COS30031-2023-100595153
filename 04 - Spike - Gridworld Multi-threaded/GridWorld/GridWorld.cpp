#include <iostream>
#include <thread>
#include "Grid.h"

using namespace std;
using namespace std::chrono;

void update(Grid* world)
{
    world->Update();
}

void render(Grid* world)
{
    world->Render();
}

int main()
{
    Grid* world = new Grid();

    thread t1(update, world);
    thread t2(render, world);

    while (world->IsRunning())
    {
        t1.join();
        t2.join();

        t1 = thread(update, world);
        t2 = thread(render, world);
    }

    t2.join();

    cout << endl << "Thanks for playing!" << endl;

    delete world;

    return 0;
}