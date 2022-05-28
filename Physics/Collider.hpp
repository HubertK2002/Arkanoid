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
	bool ballCollideWithBrick(Ball& ball, Brick& brick);
	bool brickCornersFullfillBallInequality(cordinates ballCenter, std::array<cordinates,4> brickCorners, int ballRadius );
	bool brickCornerFullfillBallInequality(cordinates ballCenter, cordinates brickCorner, int ballRadius);

private:
	int screenWidth;
	int screenHeight;
};