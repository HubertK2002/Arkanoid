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

void Ball::bounceX()
{
	speedX *= -1.0f;
}

void Ball::bounceY()
{
	speedY *= -1.0f;
}

void Ball::setX(int x)
{
	this->posX = (float)x;
}

void Ball::setY(int y)
{
	this->posY = (float)y;
}
