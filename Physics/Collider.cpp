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

bool Collider::ballCollideWithBrick(Ball& ball, Brick* brick)
{
	int ballX = ball.getCenterX();
	int ballY = ball.getCenterY();
	int brickX = brick->getCenterX();
	int brickY = brick->getCenterY();

	float xDifference = ballX - brickX;
	float yDifference = ballY - brickY;
	float xDifferenceSquare = xDifference * xDifference;
	float yDifferenceSquare = yDifference * yDifference;
	float sum = xDifferenceSquare + yDifferenceSquare;
	float distanceBetween = sqrt(sum);

	float halfdiagonal = brick->getHalfDiagonal();

	//Je�li pi�ka jest w zasi�gu ceg�y
	if (distanceBetween <= ((float)ball.getRadius() + halfdiagonal))
	{
		if (ballY >= brick->getTopLeft().second && ballY <= brick->BottomLeft().second) //Je�li znajduje si� na odpowiedniej wysoko�ci
		{
			int xDistance = abs(brickX - ballX);
			if (xDistance <= ball.getRadius() + (brick->width / 2))
			{
				ball.bounceX();
				return true;
			}
		}
		else if (ballX >= brick->getTopLeft().first && ballX <= brick->TopRight().first) //Je�li znajduje si� na odpowiedniej wysoko�ci
		{
			int yDistance = abs(brickY - ballY);
			if (yDistance <= ball.getRadius() + (brick->height / 2))
			{
				ball.bounceY();
				return true;
			}
		}
	}

	return false;

}
