#pragma once
#include <SDL.h>

class Ball
{
public:
	Ball():posX(),posY() {}
	void init(int x, int y);
	inline int getPosX() { return posX; }
	inline int getPosY() { return posY; }
private:
	float posX;
	float posY;
	const int radius = 25;
};