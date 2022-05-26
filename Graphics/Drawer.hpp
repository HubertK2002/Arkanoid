#pragma once
#include "Window.hpp"
#include "Surface.hpp"
#include "Texture.hpp"

void Render(Window& window, Texture& texture1)
{
    SDL_Renderer* r = window.getRenderer();
    SDL_RenderCopy(r,texture1.texture,NULL,NULL);
    SDL_RenderPresent(r);
}
