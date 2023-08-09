#pragma once

class Player
{
private:
	int posX;
	int posY;
public:
	Player(int lPosX, int lPosY);
	~Player();

	void Move(char dir);
};