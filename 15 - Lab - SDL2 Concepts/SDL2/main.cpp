#include <SDL.h>
#include <cstdlib>

int main(int argc, char* argv[])
{
	//Init, init check, error message.
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("SDL init failed: %s", SDL_GetError());
		return 1;
	}

	//Window creation, window check, error message.
	SDL_Window* window = SDL_CreateWindow("Task 15", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	if (!window)
	{
		SDL_Log("Window init failed: %s", SDL_GetError());
		SDL_Quit();
		return 2;
	}

	//Renderer creation, check and error message.
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!window)
	{
		SDL_Log("Renderer init failed: %s", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	bool running = true;
	SDL_Event event;

	//Set screen to green.
	SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255);

	//While open, check if I've quit, then render.
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = false;

			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_r)
			{
				SDL_SetRenderDrawColor(renderer, rand() % 256, rand() % 256, rand() % 256, 255);
			}
		}

		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}