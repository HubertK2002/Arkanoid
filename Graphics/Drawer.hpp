#pragma once
#include "Window.hpp"
#include "Surface.hpp"
#include "Texture.hpp"
#include "../Game/Bricks/Brick.hpp"
#include "../Game/Ball.hpp"
#include "../Game/Bricks/BrickContainer.hpp"
#include <vector>

void Render(Window& window, Texture& texture1)
{
    SDL_Renderer* r = window.getRenderer();
    SDL_RenderCopy(r,texture1.texture,NULL,NULL);
}

void DrawBrick(Window& window, Brick* brick, Texture& txt)
{
    SDL_Renderer* r = window.getRenderer();
    SDL_Rect tpos = brick->getTxtPos();
    SDL_RenderCopy(r, txt.texture, &tpos, &brick->pos);
}

void DrawBall(Window& window, Ball& ball, Texture& texture)
{
    SDL_Renderer* r = window.getRenderer();
    SDL_Rect pos = { ball.getPosX(),ball.getPosY(), ball.getRadius(),ball.getRadius()};
    SDL_RenderCopy(r,texture.texture,NULL,&pos);
    
}

void DrawBG(Window& window, Texture& BG, int w, int h)
{
    SDL_Renderer* r = window.getRenderer();
    SDL_Rect pos = { 0,0,w,h };
    SDL_RenderCopy(r, BG.texture, NULL, &pos);
}

void DrawBricks(Window& window, Texture& txt, std::vector<Brick*> BrickContainer)
{
    for (auto brick : BrickContainer)
    {
        DrawBrick(window, brick, txt);
    }
}

void PresentRender(Window& window)
{
    SDL_Renderer* r = window.getRenderer();
    SDL_RenderPresent(r);
}
