#include "Window.hpp"

Window::Window(int width, int height)
{
     //Initialize SDL
    SDL_Init( SDL_INIT_VIDEO );

    //Create window
    window = SDL_CreateWindow( "Arkanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );

    //Get window surface
    windowSurface = SDL_GetWindowSurface( window );
}
Window::~Window()
{
    SDL_DestroyWindow( window );
    window = NULL;
    windowSurface = NULL;
}
