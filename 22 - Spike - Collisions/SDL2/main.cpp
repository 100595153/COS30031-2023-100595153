#include <SDL.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Entity.h"
#include "Rectangle.h"
#include "Circle.h"
#include "CollisionManager.h"

using namespace std;

int main(int argc, char* argv[])
{
	//Init, init check, error message.
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("SDL init failed: %s", SDL_GetError());
		return 1;
	}

	//Window creation, window check, error message.
	SDL_Window* window = SDL_CreateWindow("Task 22", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	if (!window)
	{
		SDL_Log("Window init failed: %s", SDL_GetError());
		SDL_Quit();
		return 3;
	}

	//Renderer creation, check and error message.
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		SDL_Log("Renderer init failed: %s", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	int desiredFPS = 165;
	int frameDelay = 1000 / desiredFPS;
	Uint32 frameStart;
	int frameTime;

	bool running = true;
	bool toggleRects = true;
	SDL_Event event;

	CollisionManager* manager = new CollisionManager();

	vector<Entity*> rectangles;
	rectangles.push_back(new Rectangle("rect.bmp", new SDL_Rect({ 0, 250, 100, 100 }), 5, manager));
	rectangles.push_back(new Rectangle("rect.bmp", new SDL_Rect({350, 250, 100, 100}), 0, manager));

	vector<Entity*> circles;
	circles.push_back(new Circle(new SDL_Rect({ 0, 300, 50, 50 }), 5, manager));
	circles.push_back(new Circle(new SDL_Rect({ 400, 300, 50, 50 }), 0, manager));

	//While open, check if I've quit, then render.
	while (running)
	{
		frameStart = SDL_GetTicks();  // Get the start time of the frame
		SDL_RenderClear(renderer);

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = false;

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_1:
					toggleRects = true;
					break;
				case SDLK_2:
					toggleRects = false;
					break;
				default:
					break;
				}
			}
		}

		for (Entity* e : rectangles)
		{
			e->Update(rectangles);
		}

		for (Entity* e : circles)
		{
			e->Update(circles);
		}


		if (toggleRects)
		{
			for (Entity* e : rectangles)
			{
				e->Render(renderer);
			}
		}
		else
		{
			for (Entity* e : circles)
			{
				e->Render(renderer);
			}
		}

		SDL_RenderPresent(renderer);

		// Calculate the time taken for this frame
		frameTime = SDL_GetTicks() - frameStart;

		// If the frame was rendered faster than the desired frame delay, delay to maintain the frame rate
		if (frameTime < frameDelay) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}