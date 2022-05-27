#pragma once
#include <SDL.h>
#include "../../Graphics/Texture.hpp"
#include "../../Graphics/Surface.hpp"
#include "../../Graphics/Window.hpp"

class Brick
{
public:
	static constexpr int width = 60;
	static constexpr int height = 30;
	static constexpr SDL_Rect txtPos = {0,0,60,30};

	Brick() : pos() {}

	void init(int x, int y);
	static void staticInit(int txtPosX, int txtPosY);

	friend void DrawBrick(Window& window, Brick* brick, Texture& txt);

	inline int getX() { return (int)pos.x; }
	inline int getY() { return (int)pos.y; }

	virtual SDL_Rect getTxtPos() { return txtPos; }


protected:
	SDL_Rect pos;

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



