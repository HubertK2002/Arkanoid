#include "Brick.hpp"

void Brick::init(int x, int y)
{
	posX = (float)x;
	posY = (float)y;
}

void Brick::staticInit(int txtPosX, int txtPosY)
{
	SDL_Rect txtPos = { txtPosX,txtPosY,txtPosX + width, txtPosY + height };
}
