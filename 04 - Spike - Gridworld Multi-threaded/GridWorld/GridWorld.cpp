#include <iostream>
#include <thread>
#include "Grid.h"

using namespace std;
using namespace std::chrono;

void update(Grid* world)
{
    while (world->IsRunning())
        world->Update();
}

void render(Grid* world)
{
    while (world->IsRunning())
    {
        
        world->Render();

        system("cls");
    }
}

int main()
{
    Grid* world = new Grid();

    thread render_thread(render, world);
    thread update_thread(update, world);

    render_thread.join();
    update_thread.join();

    world->Render();

    cout << endl << "Thanks for playing!" << endl;

    return 0;
}