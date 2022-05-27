#pragma once
#include <SDL.h>

struct Surface;

class Window
{
    SDL_Window* window;
    SDL_Renderer* renderer;
public:
    Window(int width, int height);
    ~Window();

    SDL_Renderer* getRenderer(){return renderer;}

    friend void Draw(Window& window, Surface& surface);
    friend void UpdateWindow(Window& window);

};
