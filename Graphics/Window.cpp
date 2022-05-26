#include "Window.hpp"

Window::Window(int width, int height)
{
     //Initialize SDL
    SDL_Init( SDL_INIT_VIDEO );

    //Create window
    window = SDL_CreateWindow( "Arkanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );

    //Create renderer
    renderer = SDL_CreateRenderer(window,-1, 0);
    SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0xFF);
}
Window::~Window()
{
    SDL_DestroyWindow( window );
    window = NULL;
}
