#pragma once
#include <SDL2/SDL.h>

struct Surface;

class Window
{
    SDL_Window* window;
    SDL_Surface* windowSurface;
public:
    Window(int width, int height);
    ~Window();

    friend void Draw(Window& window, Surface& surface);
    friend void UpdateWindow(Window& window);
};
