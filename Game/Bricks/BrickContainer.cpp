#include "BrickContainer.hpp"

void BrickContainer::addBrick(Brick* brick, int x, int y)
{
	brickContainer.push_back(brick);
	brick->init(x, y);
}

int BrickContainer::getClosestBrickIndex(cordinates wsp)
{
	int minDistance = 999999999;
	int index = -1;
	int counter = -1;
	for (auto b : brickContainer)
	{
		counter++;
		int distance;
		int xDifference = b->getCenterX() - wsp.first;
		int yDifference = b->getCenterY() - wsp.second;
		int xPow = pow(xDifference, 2);
		int yPow = pow(yDifference, 2);
		distance = xPow + yPow;
		if (distance < minDistance)
		{
			minDistance = distance;
			index = counter;
		}
	}
	return index;
}

Brick* BrickContainer::getClosestBrick(cordinates wsp)
{
	int minDistance = 999999999;
	Brick* brickToReturn = nullptr;
	for (auto b : brickContainer)
	{
		int distance;
		int xDifference = b->getCenterX() - wsp.first;
		int yDifference = b->getCenterY() - wsp.second;
		int xPow = pow(xDifference, 2);
		int yPow = pow(yDifference, 2);
		distance = xPow + yPow;
		if (distance < minDistance)
		{
			minDistance = distance;
			brickToReturn = b;
		}
	}
	return nullptr;
}
