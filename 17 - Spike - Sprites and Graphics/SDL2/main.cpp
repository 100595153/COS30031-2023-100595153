#include <SDL.h>
#include <SDL_mixer.h>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

SDL_Rect randomisePos()
{
	int x, y;
	x = rand() % 701;
	y = rand() % 501;

	SDL_Rect result = { x, y, 100, 100 };

	return result;
}

int main(int argc, char* argv[])
{
	//Init, init check, error message.
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("SDL init failed: %s", SDL_GetError());
		return 1;
	}

	//Window creation, window check, error message.
	SDL_Window* window = SDL_CreateWindow("Task 17", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	if (!window)
	{
		SDL_Log("Window init failed: %s", SDL_GetError());
		SDL_Quit();
		return 3;
	}

	//Renderer creation, check and error message.
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!window)
	{
		SDL_Log("Renderer init failed: %s", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	//Surface and Texture for background image.
	SDL_Surface* imageSurface = SDL_LoadBMP("wamce.bmp");
	SDL_Texture* bgTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
	bool bgVisible = true;

	//Surface and Texture for tile image.
	SDL_Surface* tileSurface = SDL_LoadBMP("tile.bmp");
	SDL_Texture* tileTexture = SDL_CreateTextureFromSurface(renderer, tileSurface);
	
	//Display rects
	SDL_Rect tileRect = { 0, 0, 100, 100 };
	SDL_Rect screenRect = randomisePos();

	bool running = true;
	SDL_Event event;

	//While open, check if I've quit, then render.
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = false;

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_1:
					tileRect = { 0, 0, 100, 100 };
					screenRect = randomisePos();
					break;
				case SDLK_2:
					tileRect = { 100, 0, 100, 100 };
					screenRect = randomisePos();
					break;
				case SDLK_3:
					tileRect = { 200, 0, 100, 100 };
					screenRect = randomisePos();
					break;
				case SDLK_0:
					bgVisible = !bgVisible;
					break;
				default:
					break;
				}
			}
		}

		SDL_RenderClear(renderer);

		if (bgVisible)
		{
			SDL_RenderCopy(renderer, bgTexture, nullptr, nullptr);
		}

		SDL_RenderCopy(renderer, tileTexture, &tileRect, &screenRect);
		SDL_RenderPresent(renderer);
	}


	SDL_FreeSurface(imageSurface);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}