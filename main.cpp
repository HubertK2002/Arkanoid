#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include "Graphics/Window.hpp"
#include "Graphics/Surface.hpp"
#include "Graphics/Drawer.hpp"
#include "Graphics/Texture.hpp"
#include "Game/Bricks/Brick.hpp"
#include "Game/Ball.hpp"
#include "Physics/Collider.hpp"
#include "Game/Bricks/BrickContainer.hpp"
#include "Audio/Player.hpp"

const int sw = 1920;
const int sh = 1080;

Window window;
Surface brickBMP;
Surface ballPNG;
Surface BG;
Texture ballTexture;
Texture brickTexture;
Texture BGT;
Ball ball;
Collider collider;
BrickContainer bricks;
Player player;


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
    Brick::staticInit(0, 0);

    bricks.addBrick(new BlueBrick(),600,900);
    bricks.addBrick(new BlueBrick(), 1200, 420);
    bricks.addBrick(new GreenBrick(), 800, 200);
    bricks.addBrick(new YellowBrick(), 500, 600);
    bricks.addBrick(new OrangeBrick(), 200, 200);
    bricks.addBrick(new PinkBrick(), 300, 400);
    bricks.addBrick(new Brick(), 100, 200);

    //ball
    ball.init(1350, 330,-3,3);

    player.playMainMusicTheme();
    
}
void update()
{
    ball.update();
    if (collider.ballCollideWithWalls(ball)) player.ballWallBounceSoundEffect();
    if (bricks.hasSomething())
    {
        int ClosestBrickIndex = bricks.getClosestBrickIndex(ball.getCenterCordinates());
        if (collider.ballCollideWithBrick(ball, bricks.getBrickWithIndex(ClosestBrickIndex)))
        {
            bricks.eraseBrickWithIndex(ClosestBrickIndex);
            player.ballBrickBounceSoundEffect();
        }
    }
    

}
void draw()
{
    //Background
    DrawBG(window, BGT, sw, sh);

    //Bricks
    DrawBricks(window, brickTexture, bricks.getBricks());

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



