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
        system("cls");
        world->Render();
        this_thread::sleep_for(std::chrono::duration<double>(1.0/60.0));
    }
}

int main()
{
    Grid* world = new Grid();

    thread render_thread(render, world);
    thread update_thread(update, world);

    render_thread.join();
    update_thread.join();

    system("cls");
    world->Render();

    cout << endl << "Thanks for playing!" << endl;

    return 0;
}