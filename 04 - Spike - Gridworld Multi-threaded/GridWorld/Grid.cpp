#include "Grid.h"

void Grid::GetMoves()
{
	moves.clear();

	if (pX > 0 && grid[pX - 1][pY] != '#')
		moves.push_back('n');
	if (pY < 7 && grid[pX][pY + 1] != '#')
		moves.push_back('e');
	if (pX < 7 && grid[pX + 1][pY] != '#')
		moves.push_back('s');
	if (pY > 0 && grid[pX][pY - 1] != '#')
		moves.push_back('w');
}

Grid::Grid()
{
	running = true;

	pX = 7;
	pY = 2;

	GetMoves();
}

Grid::~Grid()
{
	delete grid;
}

bool Grid::IsRunning()
{
	return running;
}

void Grid::Update()
{
	char input = ' ';

	while (input == ' ')
	{
		//Get player input
		input = _getwche();

		cout << endl;

		//Validate input
		input = tolower(input);

		if (find(moves.begin(), moves.end(), input) != moves.end() || input == 'q')
		{
			switch (input)
			{
			case 'n':
				pX--;
				break;
			case 'e':
				pY++;
				break;
			case 's':
				pX++;
				break;
			case 'w':
				pY--;
				break;
			case 'q':
				running = false;
				break;
			default:
				cout << "Error: Invalid input not flagged correctly." << endl;
			}
		}
		else
		{
			input = ' ';
			cout << "Invalid input." << endl;
		}
	}

	if (grid[pX][pY] != ' ')
	{
		running = false;
	}

	GetMoves();
}

void Grid::Render()
{
	char dir = ' ';
	
	if (running)
	{
		cout << "You are able to move ";

		//for loop through possible move directions
		for (int i = 0; i < moves.size(); i++)
		{
			dir = toupper(moves[i]);
			cout << dir;
			if (i + 1 != moves.size())
				cout << ", ";
		}
		cout << ":" << endl;

		cout << ">> ";
	}
	else
	{
		switch (grid[pX][pY])
		{
		case 'G':
			cout << "Congratulations, you win I guess." << endl;
			break;
		case 'D':
			cout << "Oof, you have not won. Damn shame." << endl;
			break;
		default:
			cout << "An error has occured. You have entered into unknown territory and the game cannot continue." << endl;
			break;
		}
	}
}
