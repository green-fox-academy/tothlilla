//add_executable(Ex_01_Triangle main.cpp)

#include <iostream>
#include <SDL.h>
#include <math.h>

//Screen dimension constants
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 500;

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

void factoral_triangle(double left_point, double top, double size) {
  if (size <= 3) {
    //SDL_RenderDrawLine(gRenderer, left_point,top - size/2*sqrt(3), left_point + size / 2, top); nem szükséges a feladat megoldásához
    //SDL_RenderDrawLine(gRenderer, left_point,top - size/2*sqrt(3), left_point - size / 2, top);
    //SDL_RenderDrawLine(gRenderer, left_point - size / 2, top, left_point + size / 2,top);
  } else {
    SDL_RenderDrawLine(gRenderer, left_point,top - size/2*sqrt(3), left_point + size / 2, top);
    SDL_RenderDrawLine(gRenderer, left_point,top - size/2*sqrt(3), left_point - size / 2, top);
    SDL_RenderDrawLine(gRenderer, left_point - size / 2, top, left_point + size / 2,top);
    factoral_triangle(left_point, top + size*sqrt(3)/4, size/2);
    factoral_triangle(left_point-size/2, top - size*sqrt(3)/4, size/2);
    factoral_triangle(left_point+size/2, top - size*sqrt(3)/4, size/2);
  }

}
void draw()
{
  double new_x = SCREEN_WIDTH/2;
  double new_y = SCREEN_HEIGHT/2;
  double base_triangle_height = new_y;
  double base_triangle_side = 2 * base_triangle_height/sqrt(3);

  SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0x00 /*A*/);

  factoral_triangle(new_x, new_y, base_triangle_side);

}

bool init()
{
  //Initia lize SDL
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
  {
    std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
    return false;
  }

  //Create window
  gWindow = SDL_CreateWindow( "Line in the middle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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