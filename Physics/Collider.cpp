#include "Collider.hpp"

void Collider::init(int screenWidth, int screenHeight)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
}

bool Collider::ballCollideWithWalls(Ball& ball)
{
	bool collide = false;
	if (ball.getPosX() <= 0)
	{
		ball.bounceX();
		ball.setX(0);
		collide = true;
	}
	else if (ball.getPosX() >= screenWidth)
	{
		ball.bounceX();
		ball.setX(screenWidth);
		collide = true;
	}
	if (ball.getPosY() <= 0)
	{
		ball.bounceY();
		ball.setY(0);
		collide = true;
	}
	else if (ball.getPosY() >= screenHeight)
	{
		ball.bounceY();
		ball.setY(screenHeight);
		collide = true;
	}
	return collide;
}
