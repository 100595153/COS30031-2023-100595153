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
    auto lastframe = steady_clock::now();
    auto now = steady_clock::now();

    while (world->IsRunning())
    {
        if ((now - lastframe).count() >= .16)
            clog << "hi" << endl;
        //if (timepassed = 1/60)
        system("cls");
        world->Render();
    }
}

int main()
{
    Grid* world = new Grid();

    thread render_thread(render, world);
    thread update_thread(update, world);

    render_thread.join();
    update_thread.join();

    //world->Render();

    cout << endl << "Thanks for playing!" << endl;

    return 0;
}