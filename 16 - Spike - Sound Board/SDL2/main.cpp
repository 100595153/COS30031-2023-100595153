#include <SDL.h>
#include <SDL_mixer.h>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

void playSound(string file)
{
	Mix_Chunk* sound = Mix_LoadWAV(file.c_str());
	if (sound != nullptr)
	{
		Mix_PlayChannel(-1, sound, 0);
	}
}

int main(int argc, char* argv[])
{
	//Init, init check, error message.
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
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

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	Mix_Music* bgm = Mix_LoadMUS("oblivion.wav");

	bool running = true;
	SDL_Event event;

	//Set screen to black.
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

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
					playSound("potion_seller.wav");
					break;
				case SDLK_2:
					playSound("im_going_into_battle.wav");
					break;
				case SDLK_3:
					playSound("i_want_your_potions.wav");
					SDL_Log("You can't handle my potions. My potions are too strong for you, traveller.");
					break;
				case SDLK_0:
					if (Mix_PlayingMusic() == 0)
						Mix_PlayMusic(bgm, -1);
					else if (Mix_PausedMusic() == 1)
						Mix_ResumeMusic();
					else
						Mix_PauseMusic();
				default:
					break;
				}
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