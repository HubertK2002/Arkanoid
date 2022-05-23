#pragma once
#include "Window.hpp"
#include "Surface.hpp"
void Draw( Window& window, Surface& surface)
{
     SDL_BlitSurface( surface.image, NULL, window.windowSurface, NULL );
}
void UpdateWindow(Window& window)
{
    SDL_UpdateWindowSurface( window.window );
}
