#pragma once
#include <SDL.h>
#include "../../Graphics/Texture.hpp"
#include "../../Graphics/Surface.hpp"
#include "../../Graphics/Window.hpp"
#include <math.h>
#include <array>

#define cordinates std::pair<int,int> 

class Brick
{
public:
	static constexpr int width = 60;
	static constexpr int height = 30;
	static constexpr SDL_Rect txtPos = {0,0,60,30};

	Brick() : pos(),corners() {}

	void init(int x, int y);
	static void staticInit(int txtPosX, int txtPosY);

	friend void DrawBrick(Window& window, Brick* brick, Texture& txt);

	inline int getX() { return (int)pos.x; }
	inline int getY() { return (int)pos.y; }
	inline int getCenterX() { return pos.x + (width / 2); }
	inline int getCenterY() { return pos.y + (height / 2); }
	inline int getDiagonal() { return sqrt(pow(width, 2) + pow(height, 2)); }
	inline int getHalfDiagonal() { return sqrt(pow(width, 2) + pow(height, 2))/2; }
	inline cordinates getTopLeft() { return corners[0]; }
	inline cordinates TopRight() { return corners[1]; }
	inline cordinates BottomRight() { return corners[2]; }
	inline cordinates BottomLeft() { return corners[3]; }
	inline std::array<cordinates, 4> getCorners() { return corners; }

	virtual SDL_Rect getTxtPos() { return txtPos; }


protected:
	SDL_Rect pos;
	std::array<cordinates, 4> corners;

};

class PinkBrick : public Brick
{
public:
	static constexpr SDL_Rect txtPos = { 64,32,60,30 };

	SDL_Rect getTxtPos() { return txtPos; }
};

class OrangeBrick : public Brick
{
public:
	static constexpr SDL_Rect txtPos = { 64,0,60,30 };

	SDL_Rect getTxtPos() { return txtPos; }
};

class YellowBrick : public Brick
{
public:
	static constexpr SDL_Rect txtPos = { 128,0,60,30 };

	SDL_Rect getTxtPos() { return txtPos; }
};

class GreenBrick : public Brick
{
public:
	static constexpr SDL_Rect txtPos = { 192,0,60,30 };

	SDL_Rect getTxtPos() { return txtPos; }
};

class BlueBrick : public Brick
{
public:
	static constexpr SDL_Rect txtPos = { 256,0,60,30 };

	SDL_Rect getTxtPos() { return txtPos; }
};



