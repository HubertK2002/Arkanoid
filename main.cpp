#include <SDL2/SDL.h>
#include "Graphics/Window.hpp"
#include "Graphics/Surface.hpp"
#include "Graphics/Drawer.hpp"
#include "Graphics/Texture.hpp"

const int sw = 1920;
const int sh = 1080;

int main(int argc, char* args[])
{
    Window window(sw,sh);
    Surface surface("src/Bricks.bmp");
    Texture txt(window,surface);
    Render(window,txt);



    SDL_Delay( 5000 );
    SDL_Quit();
    return 0;
}




