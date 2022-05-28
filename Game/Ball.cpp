#include "Ball.hpp"

void Ball::init(int x, int y, int sx, int sy)
{
	posX = (float)x;
	posY = (float)y;
	speedX = (float)sx;
	speedY = (float)sy;
}

void Ball::update()
{
	posX += speedX;
	posY += speedY;
}
