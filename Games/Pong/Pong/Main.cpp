// Setup SDL
#include "SDL.h"
#include <iostream>

// Screen Dimentions Constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 400;

int main(int argc, char* argv[])
{
   // The window we'll be rendering to
   SDL_Window* Window = nullptr;

   // The surface constianed by the window
   SDL_Surface* ScreenSurface = nullptr;

   // Initialize SDL
   if (SDL_Init(SDL_INIT_VIDEO) < 0)
   {
      std::cout << "SDL counld not be initialized! SDL Error: " << SDL_GetError();
   }
   else
   {
      // Create window
      Window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
      if (Window == NULL)
      {
         std::cout << "Window could not be created! SDL Error: " << SDL_GetError();
      }
      else
      {
         // Get window surface
         ScreenSurface = SDL_GetWindowSurface(Window);

         // Fill the surface white
         SDL_FillRect(ScreenSurface, NULL, SDL_MapRGB(ScreenSurface->format, 0xFF, 0xFF, 0xFF));

         // Update the surface
         SDL_UpdateWindowSurface(Window);

         // Hack to get the window to stay up
         SDL_Event e;
         bool Quit = false;

         while (Quit == false)
         {
            while (SDL_PollEvent(&e))
            {
               if (e.type == SDL_QUIT) {
                  Quit = true;
               }
            }
         }
      }
   }

   // Destroy window
   SDL_DestroyWindow(Window);

   // Quit SDL subsystem
   SDL_Quit();

   return 0;
}