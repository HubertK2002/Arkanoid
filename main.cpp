#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Graphics/Window.hpp"
#include "Graphics/Surface.hpp"
#include "Graphics/Drawer.hpp"
#include "Graphics/Texture.hpp"
#include "Game/Bricks/Brick.hpp"
#include "Game/Ball.hpp"

const int sw = 1920;
const int sh = 1080;

Window window;
Surface brickBMP;
Texture brickTexture;
Brick brick;
PinkBrick pink;
OrangeBrick orange;
YellowBrick yellow;
GreenBrick green;
BlueBrick blue;
Ball ball;


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
    brickBMP.initBMP("src/Bricks.bmp");
    brickTexture.init(window, brickBMP);
    brick.init(100, 200);
    brick.staticInit(0, 0);
    pink.init(300, 400);
    orange.init(200, 200);
    yellow.init(500, 600);
    green.init(800, 200);
    blue.init(800, 400);

    ball.init(300, 300);
    
}
void update()
{

}
void draw()
{
    //Render(window, txt);
    //std::cout << brick.height;
    DrawBrick(window, &brick, brickTexture);
    DrawBrick(window, &pink, brickTexture);
    DrawBrick(window, &yellow, brickTexture);
    DrawBrick(window, &orange, brickTexture);
    DrawBrick(window, &green, brickTexture);
    DrawBrick(window, &blue, brickTexture);
    PresentRender(window);
}
void close()
{
    SDL_Delay(5000);
    SDL_Quit();
}



