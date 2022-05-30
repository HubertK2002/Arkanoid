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
	//Jeœli pi³ka jest w zasiêgu ceg³y
	if (distanceBetween <= ((float)ball.getRadius() + halfdiagonal) )
	{
		//Jeœli pi³ka nie znajduje siê w obrêbie ceg³y styka siê z wierzcho³kiem
		if (ballX < brick.getTopLeft().first || ballX > brick.BottomRight().first)
		{
			if (ballY > brick.BottomLeft().second || ballY < brick.TopRight().second)
			{
				ball.bounceX();
				ball.bounceY();
				return true;
			}
		}

		//Sprawdzenie Stycznoœci z wierzcho³kami
		if (ball.getSpeedX() > 0) //Jeœli pi³ka leci w prawo
		{
			//Jeœli pi³ka leci w dó³
			if (ball.getSpeedY() > 0)
			{
				if (brickCornerFullfillBallInequality(ball.getCenterCordinates(), brick.getTopLeft(), ball.getRadius())) // SprawdŸ stycznoœæ z lewym górnym wierzcho³kiem
				{
					ball.bounceX();
					ball.bounceY();
					return true;
				}
			} //Jeœli pi³ka leci w górê
			else
			{
				if (brickCornerFullfillBallInequality(ball.getCenterCordinates(), brick.BottomLeft(), ball.getRadius())) // SprawdŸ stycznoœæ z lewym dolnym wierzcho³kiem
				{
					ball.bounceX();
					ball.bounceY();
					return true;
				}
			}
		} 
		else //Jeœli pi³ka leci w lewo
		{
			if (ball.getSpeedY() > 0) //Jeœli pi³ka leci w dó³
			{
				if (brickCornerFullfillBallInequality(ball.getCenterCordinates(), brick.TopRight(), ball.getRadius())) // SprawdŸ stycznoœæ z prawym górnym wierzcho³kiem
				{
					ball.bounceX();
					ball.bounceY();
					return true;
				}
			}
			else // Jeœli pi³ka leci w górê
			{
				if (brickCornerFullfillBallInequality(ball.getCenterCordinates(), brick.BottomRight(), ball.getRadius())) //SprawdŸ stycznoœæ z prawym dolnym wierzcho³kiem
				{
					ball.bounceX();
					ball.bounceY();
					return true;
				}
			}
		}

		//Sprawdzenie standardowych warunków
		if (ballY >= brick.getTopLeft().second && ballY <= brick.BottomLeft().second) //Jeœli znajduje siê na odpowiedniej wysokoœci
		{
			int xDistance = abs(brickX - ballX);
			if (xDistance <= ball.getRadius() + (brick.width / 2))
			{
				ball.bounceX();
				return true;
			}
		}
		else if (ballX >= brick.getTopLeft().first && ballX <= brick.TopRight().first) //Jeœli znajduje siê na odpowiedniej wysokoœci
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
	//Jeœli pi³ka jest w zasiêgu ceg³y
	if (distanceBetween <= ((float)ball.getRadius() + halfdiagonal))
	{
		//Jeœli pi³ka nie znajduje siê w obrêbie ceg³y styka siê z wierzcho³kiem
		/*if (ballX < brick->getTopLeft().first || ballX > brick->BottomRight().first)
		{
			if (ballY > brick->BottomLeft().second || ballY < brick->TopRight().second)
			{
				ball.bounceX();
				ball.bounceY();
				return true;
			}
		}*/

		//Sprawdzenie Stycznoœci z wierzcho³kami
	/*	if (ball.getSpeedX() > 0) //Jeœli pi³ka leci w prawo
		{
			//Jeœli pi³ka leci w dó³
			if (ball.getSpeedY() > 0)
			{
				if (brickCornerFullfillBallInequality(ball.getCenterCordinates(), brick->getTopLeft(), ball.getRadius())) // SprawdŸ stycznoœæ z lewym górnym wierzcho³kiem
				{
					ball.bounceX();
					ball.bounceY();
					return true;
				}
			} //Jeœli pi³ka leci w górê
			else
			{
				if (brickCornerFullfillBallInequality(ball.getCenterCordinates(), brick->BottomLeft(), ball.getRadius())) // SprawdŸ stycznoœæ z lewym dolnym wierzcho³kiem
				{
					ball.bounceX();
					ball.bounceY();
					return true;
				}
			}
		}
		else //Jeœli pi³ka leci w lewo
		{
			if (ball.getSpeedY() > 0) //Jeœli pi³ka leci w dó³
			{
				if (brickCornerFullfillBallInequality(ball.getCenterCordinates(), brick->TopRight(), ball.getRadius())) // SprawdŸ stycznoœæ z prawym górnym wierzcho³kiem
				{
					ball.bounceX();
					ball.bounceY();
					return true;
				}
			}
			else // Jeœli pi³ka leci w górê
			{
				if (brickCornerFullfillBallInequality(ball.getCenterCordinates(), brick->BottomRight(), ball.getRadius())) //SprawdŸ stycznoœæ z prawym dolnym wierzcho³kiem
				{
					ball.bounceX();
					ball.bounceY();
					return true;
				}
			}
		}*/

		//Sprawdzenie standardowych warunków
		if (ballY >= brick->getTopLeft().second && ballY <= brick->BottomLeft().second) //Jeœli znajduje siê na odpowiedniej wysokoœci
		{
			int xDistance = abs(brickX - ballX);
			if (xDistance <= ball.getRadius() + (brick->width / 2))
			{
				ball.bounceX();
				return true;
			}
		}
		else if (ballX >= brick->getTopLeft().first && ballX <= brick->TopRight().first) //Jeœli znajduje siê na odpowiedniej wysokoœci
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
