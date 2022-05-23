#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

bool init();
bool loadMedia();
void close();

SDL_Window* mainWindow = NULL;
SDL_Surface* mainWindowSurface = NULL;
SDL_Surface* image = NULL;

int main(int argc, char* args[])
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Apply the image
            SDL_BlitSurface( image, NULL, mainWindowSurface, NULL );
            //Update the surface
            SDL_UpdateWindowSurface( mainWindow );
            //Wait two seconds
            SDL_Delay( 5000 );
        }
    }

    //Free resources and close SDL
    close();


    return 0;
}

bool init()
{
     //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        mainWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( mainWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            mainWindowSurface = SDL_GetWindowSurface( mainWindow );
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load splash image
    image = SDL_LoadBMP( "src/Bricks.bmp" );
    if( image == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "src/Bricks.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface( image );
    image = NULL;

    //Destroy window
    SDL_DestroyWindow( mainWindow );
    mainWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}
