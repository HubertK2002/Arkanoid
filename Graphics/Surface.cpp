#include "Surface.hpp"
#include <iostream>

Surface::Surface(std::string source)
{
    image = SDL_LoadBMP( source.c_str() );
}
Surface::~Surface()
{
    SDL_FreeSurface( image );
    image = NULL;
}

void Surface::initBMP(std::string source)
{
    image = SDL_LoadBMP(source.c_str());
    if (image == NULL) std::cout << "Unable to load surface";
}

void Surface::initPNG(std::string source)
{
    image = IMG_Load(source.c_str());
}
