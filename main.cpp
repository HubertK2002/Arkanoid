#include <SDL.h>
#include <iostream>
#include "Graphics/Window.hpp"
#include "Graphics/Surface.hpp"
#include "Graphics/Drawer.hpp"
#include "Graphics/Texture.hpp"
#include "Game/Bricks/Brick.hpp"

const int sw = 1920;
const int sh = 1080;

Window window;
Surface surface;
Texture txt;
Brick brick;


void init();
void update();
void draw();
void close();

int main(int argc, char* args[])
{
    init();
    update();
    draw();
    close();

    return 0;
}

void init()
{
    window.init(sw, sh);
    surface.init("src/Bricks.bmp");
    txt.init(window, surface);
    brick.init(100, 200);
    brick.staticInit(0, 0);
}
void update()
{

}
void draw()
{
    Render(window, txt);
    std::cout << brick.height;
}
void close()
{
    SDL_Delay(5000);
    SDL_Quit();
}



