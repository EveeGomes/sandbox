// Setup SDL
#include "SDL.h"
#include <iostream>

#include "Ball.h"

// Screen Dimentions Constants
const int gSCREEN_WIDTH = 800;
const int gSCREEN_HEIGHT = 400;

// The window we'll be rendering to
SDL_Window* gWindow = nullptr;
// The surface contained by the window
SDL_Surface* gScreenSurface = nullptr;

bool gQuit = false;

// From Mike Shah *_* https://www.youtube.com/watch?v=9P_MAgSNZx8&ab_channel=MikeShah
// Similar to what we have in OpenGL (Context), a Renderer is where we hold the state. It takes up the whole screen/window. 
SDL_Renderer* gRenderer = nullptr;

void InitializeSDLWindow()
{
   // Initialize SDL
   if (SDL_Init(SDL_INIT_VIDEO) < 0)
   {
      std::cout << "SDL counld not be initialized! SDL Error: " << SDL_GetError();
   }
   else
   {
      // Create window
      gWindow = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gSCREEN_WIDTH, gSCREEN_HEIGHT, SDL_WINDOW_SHOWN);
      
      if (gWindow == NULL)
      {
         std::cout << "Window could not be created! SDL Error: " << SDL_GetError();
      }
      else
      {
         // Create renderer for window
         gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
         if (gRenderer == NULL) {
            std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError();
            SDL_DestroyWindow(gWindow);
            SDL_Quit();
            return;
         }

         // Set renderer color to white
         SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

         // Get window surface
         gScreenSurface = SDL_GetWindowSurface(gWindow);

         // Fill the surface white
         SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 0, 0, 0));

         // Update the surface
         SDL_UpdateWindowSurface(gWindow);
      }
   }
}

void Input()
{
   // Check for quit event to close the window
   SDL_Event e;

   // Constantly pull and see if there are any events here
   while (SDL_PollEvent(&e) != 0)
   {
      if (e.type == SDL_QUIT) {
         gQuit = true;
      }
   }
}

void MainLoop()
{
   Ball FirstBall{50, 50, 3, gRenderer};

   // While application is running -> infinite loop
   while (!gQuit)
   {
      // (1) Handle input
      Input();

      // (2) Handle Updates
      // (3) Clear and Draw the screen

      // Since SDL_RenderClear gives us a white screen once it clears, we should set the color first so it leaves in the Renderer state.
      SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
      // Gives us a clear "canvas"
      SDL_RenderClear(gRenderer);

      // Do our drawing
      // But first, change the state of what we're drawing, i.e, we use the renderer which holds these states
      SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
      FirstBall.Draw();

      // Finally show what we've drawn
      SDL_RenderPresent(gRenderer);
   }
}

void CleanUp()
{
   SDL_DestroyRenderer(gRenderer);

   // Destroy window
   SDL_DestroyWindow(gWindow);

   // Quit SDL subsystem
   SDL_Quit();
}


int main(int argc, char* argv[])
{

   InitializeSDLWindow();

   // Create rectangles (paddles)
   // Create the ball


   MainLoop();

   CleanUp();

   return 0;
}

