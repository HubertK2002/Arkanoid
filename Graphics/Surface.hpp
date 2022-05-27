#pragma once
#include <SDL.h>
#include <string>

struct Surface
{
    SDL_Surface* image;

    Surface(std::string source);
    ~Surface();

};
