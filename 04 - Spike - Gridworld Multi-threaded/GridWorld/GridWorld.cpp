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

    thread update_thread(update, world);
    thread render_thread(render, world);

    while (world->IsRunning())
    {
        if (update_thread.joinable())
        {
            update_thread.join();
            update_thread = thread(update, world);
        }
            
        
        if (render_thread.joinable())
        {
            render_thread.join();
            render_thread = thread(render, world);
        }
    }

    if (update_thread.joinable())
        update_thread.detach();

    if (render_thread.joinable())
        render_thread.join();

    cout << endl << "Thanks for playing!" << endl;

    return 0;
}