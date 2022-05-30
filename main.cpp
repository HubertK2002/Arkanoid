#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Graphics/Window.hpp"
#include "Graphics/Surface.hpp"
#include "Graphics/Drawer.hpp"
#include "Graphics/Texture.hpp"
#include "Game/Bricks/Brick.hpp"
#include "Game/Ball.hpp"
#include "Physics/Collider.hpp"

const int sw = 1920;
const int sh = 1080;

Window window;
Surface brickBMP;
Surface ballPNG;
Surface BG;
Texture ballTexture;
Texture brickTexture;
Texture BGT;
Brick brick;
PinkBrick pink;
OrangeBrick orange;
YellowBrick yellow;
GreenBrick green;
BlueBrick blue;
Ball ball;
Collider collider;


void init();
void update();
void draw();
void close();

int main(int argc, char* args[])
{
    init();
    bool cont = true;
    SDL_Event e;
    while (cont)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.key.keysym.scancode == SDL_SCANCODE_BACKSPACE)
            {
                cont = false;
            }
        }
        update();
        draw();
    }
    close();

    return 0;
}

void init()
{
    window.init(sw, sh);
    //Surfaces
    brickBMP.initBMP("src/Bricks.bmp");
    ballPNG.initBMP("src/Ball2.bmp");
    BG.initBMP("src/bg.bmp");
    //textures
    brickTexture.init(window, brickBMP);
    ballTexture.init(window, ballPNG);
    BGT.init(window, BG);

    //Collider
    collider.init(sw, sh);

    //bricks
    brick.init(100, 200);
    brick.staticInit(0, 0);
    pink.init(300, 400);
    orange.init(200, 200);
    yellow.init(500, 600);
    green.init(800, 200);
    blue.init(1200, 420);

    //ball
    ball.init(1350, 330,-3,3);
    
}
void update()
{
    ball.update();
    collider.ballCollideWithWalls(ball);
    collider.ballCollideWithBrick(ball, blue);
}
void draw()
{
    //Background
    DrawBG(window, BGT, sw, sh);

    //Bricks
    DrawBrick(window, &brick, brickTexture);
    DrawBrick(window, &pink, brickTexture);
    DrawBrick(window, &yellow, brickTexture);
    DrawBrick(window, &orange, brickTexture);
    DrawBrick(window, &green, brickTexture);
    DrawBrick(window, &blue, brickTexture);
    //ball
    DrawBall(window, ball, ballTexture);
    //Update render
    PresentRender(window);
}
void close()
{
    //SDL_Delay(5000);
    SDL_Quit();
}



