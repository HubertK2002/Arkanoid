#pragma once
#include <SDL.h>
#include "../Graphics/Window.hpp"
#include "../Graphics/Texture.hpp"
#include <array>

#define cordinates std::pair<int,int>

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
	inline int getCenterX() { return (int)posX + (float)radius; }
	inline int getCenterY() { return (int)posY + (float)radius; }
	inline int getRadius() { return radius; }
	inline int getHalfRadius() { return radius / 2; }
	inline cordinates getCenterCordinates() { return cordinates{ getCenterX(),getCenterY() }; }
	inline float getSpeedX() { return speedX; }
	inline float getSpeedY() { return speedY; }

	friend void DrawBall(Window& window, Ball& ball, Texture& texture);

private:
	float posX;
	float posY;
	const int radius = 25;
	float speedX;
	float speedY;
};