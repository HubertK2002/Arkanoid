#include "Window.hpp"
#include <iostream>

Window::Window(int width, int height)
{
     //Initialize SDL
    SDL_Init( SDL_INIT_EVERYTHING );

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        std::cout << "could not initialize SDL_Image";
    }

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

void Window::init(int width, int height)
{
    //Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    //Create window
    window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    //Create renderer
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}
