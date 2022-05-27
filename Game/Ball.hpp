#pragma once
#include <SDL.h>
#include "../Graphics/Window.hpp"
#include "../Graphics/Texture.hpp"

class Ball
{
public:
	Ball():posX(),posY() {}
	void init(int x, int y);
	inline int getPosX() { return (int)posX; }
	inline int getPosY() { return (int)posY; }
	inline int getRadius() { return radius; }

	friend void DrawBall(Window& window, Ball& ball, Texture& texture);

private:
	float posX;
	float posY;
	const int radius = 25;
};