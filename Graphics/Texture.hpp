#pragma once
#include <SDL2/SDL.h>
#include "Window.hpp"
#include "Surface.hpp"

struct Texture
{
    SDL_Texture* texture;
    Texture(Window& window,Surface& surface);
};
