#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

struct Surface
{
    SDL_Surface* image;

    Surface(std::string source);
    Surface() : image(NULL) {}
    ~Surface();

    void initBMP(std::string source);
    void initPNG(std::string source);

};
