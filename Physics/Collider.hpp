#pragma once
#include "../Game/Ball.hpp"
class Collider
{
public:
	Collider() :screenWidth(), screenHeight() {}
	void init(int screenWidth, int screenHeight);
	bool ballCollideWithWalls(Ball& ball);

private:
	int screenWidth;
	int screenHeight;
};