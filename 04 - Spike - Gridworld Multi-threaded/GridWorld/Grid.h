#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Grid
{
private:
	char grid[8][8] = {
		{ '#', '#', '#', '#', '#', '#', '#', '#' },
		{ '#', 'G', ' ', 'D', '#', 'D', ' ', '#' },
		{ '#', ' ', ' ', ' ', '#', ' ', ' ', '#' },
		{ '#', '#', '#', ' ', '#', ' ', 'D', '#' },
		{ '#', ' ', ' ', ' ', '#', ' ', ' ', '#' },
		{ '#', ' ', '#', '#', '#', '#', ' ', '#' },
		{ '#', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
		{ '#', '#', ' ', '#', '#', '#', '#', '#' },
	};

	string header = "Welcome To Grid World: Griddy, Set, Go\n";
	int pX;
	int pY;

	vector<char> moves;
	bool running;

	void GetMoves();

public:
	Grid();
	~Grid();

	bool IsRunning();

	void Update();
	void Render();
};