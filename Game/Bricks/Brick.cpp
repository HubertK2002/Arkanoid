#include "Brick.hpp"

Brick::Brick(int x, int y)
{
	pos = { x,y,width,height };
	corners[0] = cordinates{ x,y };						//Topleft
	corners[1] = cordinates{ x + width,y };				//TopRight
	corners[2] = cordinates{ x + width, y + height };	//BottomRight
	corners[3] = cordinates{ x, y + height };			//BottomLeft
}

void Brick::init(int x, int y)
{
	pos = { x,y,width,height };
	corners[0] = cordinates{ x,y };						//Topleft
	corners[1] = cordinates{ x + width,y };				//TopRight
	corners[2] = cordinates{ x + width, y + height };	//BottomRight
	corners[3] = cordinates{ x, y + height };			//BottomLeft

}

void Brick::staticInit(int txtPosX, int txtPosY)
{
	SDL_Rect txtPos = { txtPosX,txtPosY,txtPosX + width, txtPosY + height };
}

