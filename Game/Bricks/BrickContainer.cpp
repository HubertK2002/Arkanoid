#include "BrickContainer.hpp"

void BrickContainer::addBrick(Brick* brick, int x, int y)
{
	brickContainer.push_back(brick);
	brick->init(x, y);
}
