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

void Surface::init(std::string source)
{
    image = SDL_LoadBMP(source.c_str());
}
