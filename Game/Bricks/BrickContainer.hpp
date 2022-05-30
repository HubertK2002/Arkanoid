#pragma once
#include "Brick.hpp"
#include <vector>

#define Container std::vector<Brick*>

class BrickContainer
{
public:
	BrickContainer() :brickContainer() {}
	void addBrick(Brick* brick, int x, int y);
	inline Container getBricks() { return brickContainer; }
private:
	Container brickContainer;
};