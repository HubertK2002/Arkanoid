#pragma once
#include <SDL.h>
class Brick
{
public:
	static constexpr int width = 20;
	static constexpr int height = 10;
	static SDL_Rect txtPos;

	Brick() : posX(0), posY(0) {}

	void init(int x, int y);
	static void staticInit(int txtPosX, int txtPosY);

private:
	float posX;
	float posY;

};