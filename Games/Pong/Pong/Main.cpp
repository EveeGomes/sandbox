// Setup SDL
#include "SDL.h"
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>
#include <string>
#include <sstream>

#include "Ball.h"
//#include "LTexture.h"

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
         gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // create vsynced renderer for window
         if (gRenderer == NULL) 
         {
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
      if (e.type == SDL_QUIT) 
      {
         gQuit = true;
      }
   }
}

void MainLoop()
{
   Ball FirstBall{50, 50, 3, gRenderer};
   FirstBall.SetSpeeds(0.02f, 0.f);

   //// For calculating frames:
   //SDL_Color textColor = { 255, 255, 255, 255 }; // white

   //// Current time start time
   //Uint32 startTime = 0;

   ////The frames per second timer
   //LTimer fpsTimer;

   //In memory text stream
   std::stringstream timeText;

   // While application is running -> infinite loop
   while (!gQuit)
   {
      // (1) Handle input
      Input();

      // (2) Handle Updates

      //// Change the Ball obj x parameter every frame
      //FirstBall.m_CenterX += FirstBall.m_SpeedX * ((SDL_GetTicks() - startTime)/100);
      //std::cout << FirstBall.m_CenterX << "\n";
      //   

      //if (FirstBall.m_CenterX > gSCREEN_WIDTH)
      //{
      //   FirstBall.m_CenterX = gSCREEN_WIDTH;
      //   FirstBall.m_SpeedX *= -1.1f;
      //}

      //if (FirstBall.m_CenterX < 0.f)
      //{
      //   FirstBall.m_CenterX = 0.f;
      //   FirstBall.m_SpeedX *= -1.1f;
      //}

      // Following LazyFoo SDL tutorial 22_Timing @https://lazyfoo.net/tutorials/SDL/22_timing/index.php
         
      // Set text to be rendered
      //timeText.str("");
      //timeText << "Milliseconds since start time " << SDL_GetTicks() - startTime;

      //// Render text
      //if (!gTimeTextTexture.loadFromRenderedText(timeText.str().c_str(), textColor))
      //{
      //   printf("Unable to render time texture!\n");
      //}

      //Calculate and correct fps
      //float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
      //if (avgFPS > 2000000)
      //{
      //   avgFPS = 0;
      //}
      //std::cout << avgFPS << "\n";

      // (3) Clear and Draw the screen

      // Since SDL_RenderClear gives us a white screen once it clears, we should set the color first so it leaves in the Renderer state.
      SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // all black
      // Gives us a clear "canvas"
      SDL_RenderClear(gRenderer);

      // Do our drawing
      // But first, change the state of what we're drawing, i.e, we use the renderer which holds these states
      SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
      FirstBall.Draw();
      // Instead of calling Draw, 

      // Finally show what we've drawn
      SDL_RenderPresent(gRenderer);
   }
}

void CleanUp()
{
  // Destroy window
   SDL_DestroyRenderer(gRenderer);
   SDL_DestroyWindow(gWindow);
   gWindow = NULL;
   gRenderer = NULL;

   //Quit SDL subsystems
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

