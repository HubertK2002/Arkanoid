#include "Surface.hpp"

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
}

void Surface::initPNG(std::string source)
{
    image = IMG_Load(source.c_str());
}
