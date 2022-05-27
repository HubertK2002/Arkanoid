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

	friend void DrawBrick(Window& window, Brick& brick, Texture& txt);

	inline int getX() { return (int)pos.x; }
	inline int getY() { return (int)pos.y; }


private:
	SDL_Rect pos;

};