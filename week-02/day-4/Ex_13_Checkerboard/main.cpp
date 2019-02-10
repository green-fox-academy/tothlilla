#include <iostream>
#include <SDL.h>
#include <ctime>
//Screen dimension constants
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 480;

//Draws geometry on the canvas
void draw();

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The window renderer
SDL_Renderer* gRenderer = nullptr;

void draw() {
   /* int red;
    int green;
    int blue;
    int x = 0;
    int y = 0;

    for (int i = 0; i < SCREEN_HEIGHT / 10; ++i) {
        red += 122;
        green += 122;
        blue += 122;
        SDL_SetRenderDrawColor(gRenderer, red, green, blue, 0xFF);
        SDL_Rect fillRect = {x, y, 10, 10};
        SDL_RenderFillRect(gRenderer, &fillRect);
        for (int j = 0; j < SCREEN_WIDTH / 10; j++) {
            red -= 122;
            green -= 122;
            blue -= 122;
            SDL_SetRenderDrawColor(gRenderer, red, green, blue, 0xFF);
            SDL_Rect fillRect = {x, y, 10, 10};
            SDL_RenderFillRect(gRenderer, &fillRect);


            x += 10;
        }
        x = 0;
        y += 10;
    }

    */
   int red ;
    int green = 100;
    int blue = 100;
    int x = 0;
    int y = 0;
    int a =SCREEN_WIDTH / 10;
    for (int i = 0; i < SCREEN_HEIGHT / 10; ++i) {

        SDL_SetRenderDrawColor(gRenderer, red, green, blue, 0xFF);
        SDL_Rect fillRect = {x, y, 10, 10};
        SDL_RenderFillRect(gRenderer, &fillRect);

        for (int j = 0; j < SCREEN_WIDTH / 10; j++) {

            if (a % 2 == 0) {
                red = 22;

                SDL_SetRenderDrawColor(gRenderer, red, green, blue, 0xFF);
                SDL_Rect fillRect = {x, y, 10, 10};
                SDL_RenderFillRect(gRenderer, &fillRect);
            } else {
                red = 122;

                SDL_SetRenderDrawColor(gRenderer, red, green, blue, 0xFF);
                SDL_Rect fillRect = {x, y, 10, 10};
                SDL_RenderFillRect(gRenderer, &fillRect);
            }
            x += 10;
            a += 1;
        }
        x = 0;
        y += 10;
        a += 1;

    }

}
// Fill the canvas with a checkerboard pattern.


bool init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow( "Checkerboard", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == nullptr )
    {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( gRenderer == nullptr )
    {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    return true;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main( int argc, char* args[] )
{
    srand(time(0));
    //Start up SDL and create window
    if( !init() )
    {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit ) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        draw();

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}