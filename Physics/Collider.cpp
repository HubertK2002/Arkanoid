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

bool Collider::ballCollideWithBrick(Ball& ball, Brick& brick)
{
	int ballX = ball.getCenterX();
	int ballY = ball.getCenterY();
	int brickX = brick.getCenterX();
	int brickY = brick.getCenterY();

	float xDifference = ballX - brickX;
	float yDifference = ballY - brickY;
	float xDifferenceSquare = xDifference * xDifference;
	float yDifferenceSquare = yDifference * yDifference;
	float sum = xDifferenceSquare + yDifferenceSquare;
	float distanceBetween = sqrt(sum);

	float halfdiagonal = brick.getHalfDiagonal();
	//Je�li pi�ka jest w zasi�gu ceg�y
	if (distanceBetween <= ((float)ball.getRadius() + halfdiagonal) )
	{
		//Je�li pi�ka nie znajduje si� w obr�bie ceg�y styka si� z wierzcho�kiem
		if (ballX < brick.getTopLeft().first || ballX > brick.BottomRight().first)
		{
			if (ballY > brick.BottomLeft().second || ballY < brick.TopRight().second)
			{
				ball.bounceX();
				ball.bounceY();
				return true;
			}
		}

		//Sprawdzenie Styczno�ci z wierzcho�kami
		if (ball.getSpeedX() > 0) //Je�li pi�ka leci w prawo
		{
			//Je�li pi�ka leci w d�
			if (ball.getSpeedY() > 0)
			{
				if (brickCornerFullfillBallInequality(ball.getCenterCordinates(), brick.getTopLeft(), ball.getRadius())) // Sprawd� styczno�� z lewym g�rnym wierzcho�kiem
				{
					ball.bounceX();
					ball.bounceY();
					return true;
				}
			} //Je�li pi�ka leci w g�r�
			else
			{
				if (brickCornerFullfillBallInequality(ball.getCenterCordinates(), brick.BottomLeft(), ball.getRadius())) // Sprawd� styczno�� z lewym dolnym wierzcho�kiem
				{
					ball.bounceX();
					ball.bounceY();
					return true;
				}
			}
		} 
		else //Je�li pi�ka leci w lewo
		{
			if (ball.getSpeedY() > 0) //Je�li pi�ka leci w d�
			{
				if (brickCornerFullfillBallInequality(ball.getCenterCordinates(), brick.TopRight(), ball.getRadius())) // Sprawd� styczno�� z prawym g�rnym wierzcho�kiem
				{
					ball.bounceX();
					ball.bounceY();
					return true;
				}
			}
			else // Je�li pi�ka leci w g�r�
			{
				if (brickCornerFullfillBallInequality(ball.getCenterCordinates(), brick.BottomRight(), ball.getRadius())) //Sprawd� styczno�� z prawym dolnym wierzcho�kiem
				{
					ball.bounceX();
					ball.bounceY();
					return true;
				}
			}
		}

		//Sprawdzenie standardowych warunk�w
		if (ballY >= brick.getTopLeft().second && ballY <= brick.BottomLeft().second) //Je�li znajduje si� na odpowiedniej wysoko�ci
		{
			int xDistance = abs(brickX - ballX);
			if (xDistance <= ball.getRadius() + (brick.width / 2))
			{
				ball.bounceX();
				return true;
			}
		}
		else if (ballX >= brick.getTopLeft().first && ballX <= brick.TopRight().first) //Je�li znajduje si� na odpowiedniej wysoko�ci
		{
			int yDistance = abs(brickY - ballY);
			if (yDistance <= ball.getRadius() + (brick.height / 2))
			{
				ball.bounceY();
				return true;
			}
		}
		
	}

	return false;

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
		//Je�li pi�ka nie znajduje si� w obr�bie ceg�y styka si� z wierzcho�kiem
		/*if (ballX < brick->getTopLeft().first || ballX > brick->BottomRight().first)
		{
			if (ballY > brick->BottomLeft().second || ballY < brick->TopRight().second)
			{
				ball.bounceX();
				ball.bounceY();
				return true;
			}
		}*/

		//Sprawdzenie Styczno�ci z wierzcho�kami
	/*	if (ball.getSpeedX() > 0) //Je�li pi�ka leci w prawo
		{
			//Je�li pi�ka leci w d�
			if (ball.getSpeedY() > 0)
			{
				if (brickCornerFullfillBallInequality(ball.getCenterCordinates(), brick->getTopLeft(), ball.getRadius())) // Sprawd� styczno�� z lewym g�rnym wierzcho�kiem
				{
					ball.bounceX();
					ball.bounceY();
					return true;
				}
			} //Je�li pi�ka leci w g�r�
			else
			{
				if (brickCornerFullfillBallInequality(ball.getCenterCordinates(), brick->BottomLeft(), ball.getRadius())) // Sprawd� styczno�� z lewym dolnym wierzcho�kiem
				{
					ball.bounceX();
					ball.bounceY();
					return true;
				}
			}
		}
		else //Je�li pi�ka leci w lewo
		{
			if (ball.getSpeedY() > 0) //Je�li pi�ka leci w d�
			{
				if (brickCornerFullfillBallInequality(ball.getCenterCordinates(), brick->TopRight(), ball.getRadius())) // Sprawd� styczno�� z prawym g�rnym wierzcho�kiem
				{
					ball.bounceX();
					ball.bounceY();
					return true;
				}
			}
			else // Je�li pi�ka leci w g�r�
			{
				if (brickCornerFullfillBallInequality(ball.getCenterCordinates(), brick->BottomRight(), ball.getRadius())) //Sprawd� styczno�� z prawym dolnym wierzcho�kiem
				{
					ball.bounceX();
					ball.bounceY();
					return true;
				}
			}
		}*/

		//Sprawdzenie standardowych warunk�w
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

bool Collider::brickCornersFullfillBallInequality(cordinates ballCenter, std::array<cordinates, 4> brickCorners, int ballRadius)
{
	for (auto c : brickCorners)
	{
		float xDistance = pow((float)c.first - (float)ballCenter.first, 2);
		float yDistance = pow((float)c.second - (float)ballCenter.second, 2);
		float rSquare = pow((float)ballRadius, 2);
		if (xDistance + yDistance <= rSquare) return true;
	}
	return false;
}

bool Collider::brickCornerFullfillBallInequality(cordinates ballCenter, cordinates brickCorner, int ballRadius)
{
	float xDistance = pow((float)brickCorner.first - (float)ballCenter.first, 2);
	float yDistance = pow((float)brickCorner.second - (float)ballCenter.second, 2);
	float rSquare = pow((float)ballRadius, 2);
	
	if (xDistance + yDistance <= rSquare) return true;
	else return false;
}
