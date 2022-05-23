#pragma once
#include <SDL2/SDL.h>
#include <string>

struct Surface
{
    SDL_Surface* image;

    Surface(std::string source);
    ~Surface();

};
