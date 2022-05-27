#pragma once
#include <SDL.h>
#include <string>

struct Surface
{
    SDL_Surface* image;

    Surface(std::string source);
    Surface() : image(NULL) {}
    ~Surface();

    void init(std::string source);

};
