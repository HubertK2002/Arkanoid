#pragma once
#include <SDL.h>
#include "../Graphics/Window.hpp"
#include "../Graphics/Texture.hpp"

class Ball
{
public:
	Ball():posX(),posY(),speedX(),speedY() {}
	void init(int x, int y, int sx, int sy);
	void update();
	void bounceX();
	void bounceY();
	void setX(int x);
	void setY(int y);
	inline int getPosX() { return (int)posX; }
	inline int getPosY() { return (int)posY; }
	inline int getRadius() { return radius; }

	friend void DrawBall(Window& window, Ball& ball, Texture& texture);

private:
	float posX;
	float posY;
	const int radius = 25;
	float speedX;
	float speedY;
};