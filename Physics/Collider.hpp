#pragma once
#include "../Game/Ball.hpp"
#include "../Game/Bricks/Brick.hpp"
#include <array>
#include <cmath>

#define cordinates std::pair<int,int>

class Collider
{
public:
	Collider() :screenWidth(), screenHeight() {}
	void init(int screenWidth, int screenHeight);
	bool ballCollideWithWalls(Ball& ball);
	bool ballCollideWithBrick(Ball& ball, Brick* brick);

private:
	int screenWidth;
	int screenHeight;
};