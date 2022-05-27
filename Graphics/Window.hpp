#pragma once
#include <SDL.h>
#include <SDL_image.h>

struct Surface;

class Window
{
    SDL_Window* window;
    SDL_Renderer* renderer;
public:
    Window(int width, int height);
    Window() : window(NULL), renderer(NULL) {}
    ~Window();

    SDL_Renderer* getRenderer(){return renderer;}
    void init(int width, int height);

    friend void Draw(Window& window, Surface& surface);
    friend void UpdateWindow(Window& window);

};
