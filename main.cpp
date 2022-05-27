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
PinkBrick pink;
OrangeBrick orange;
YellowBrick yellow;
GreenBrick green;
BlueBrick blue;


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
    pink.init(300, 400);
    orange.init(200, 200);
    yellow.init(500, 600);
    green.init(800, 200);
    blue.init(800, 400);
    
}
void update()
{

}
void draw()
{
    //Render(window, txt);
    //std::cout << brick.height;
    DrawBrick(window, &brick,txt);
    DrawBrick(window, &pink, txt);
    DrawBrick(window, &yellow, txt);
    DrawBrick(window, &orange, txt);
    DrawBrick(window, &green, txt);
    DrawBrick(window, &blue, txt);
    PresentRender(window);
}
void close()
{
    SDL_Delay(5000);
    SDL_Quit();
}



