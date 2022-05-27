#include "Brick.hpp"

void Brick::init(int x, int y)
{
	pos = { x,y,width,height };
}

void Brick::staticInit(int txtPosX, int txtPosY)
{
	SDL_Rect txtPos = { txtPosX,txtPosY,txtPosX + width, txtPosY + height };
}
