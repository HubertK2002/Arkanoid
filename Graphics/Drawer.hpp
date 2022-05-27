#pragma once
#include "Window.hpp"
#include "Surface.hpp"
#include "Texture.hpp"
#include "../Game/Bricks/Brick.hpp"

void Render(Window& window, Texture& texture1)
{
    SDL_Renderer* r = window.getRenderer();
    SDL_RenderCopy(r,texture1.texture,NULL,NULL);
}

void DrawBrick(Window& window, Brick& brick, Texture& txt)
{
    SDL_Renderer* r = window.getRenderer();
    SDL_Rect tpos = brick.txtPos;
    SDL_RenderCopy(r, txt.texture, &tpos, &brick.pos);
}

void PresentRender(Window& window)
{
    SDL_Renderer* r = window.getRenderer();
    SDL_RenderPresent(r);
}
