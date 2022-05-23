#include <SDL2/SDL.h>
#include "Graphics/Window.hpp"
#include "Graphics/Surface.hpp"
#include "Graphics/Drawer.hpp"

const int sw = 1920;
const int sh = 1000;

int main(int argc, char* args[])
{
    Window window(sw,sh);
    Surface surface("src/Bricks.bmp");
    Draw(window, surface);
    UpdateWindow(window);


    SDL_Delay( 5000 );
    SDL_Quit();
    return 0;
}




