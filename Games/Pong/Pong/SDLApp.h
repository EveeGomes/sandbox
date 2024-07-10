#ifndef SDLAPP_H
#define SDLAPP_H

// From: https://www.youtube.com/watch?v=GvX3jP7BR6I&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=30&ab_channel=MikeShah

// C++ Libraries
#include <iostream>

// Third party
#include "SDL.h"

class SDLApp
{
public:
   // Constructor
   SDLApp(const char* title, int x, int y, int w, int h)
   {
      /** 
      * Initialize the video subsystem.
      * If it returns less than 1, then an error code
      *  will be received.
      */
      if (SDL_Init(SDL_INIT_VIDEO) < 0)
      {
         std::cout << "SDL could not be initialized! SDL Error: " << SDL_GetError();
      }
      else
      {
         std::cout << "SDL Video system is ready to go.\n";
      }
      /** 
      * Request a window to be created for our platform.
      * The parameters are for the title, x and y positions,
      *  the width and height of the window
      */
      m_Window = SDL_CreateWindow(title, x, y, w, h, SDL_WINDOW_SHOWN);
      if (m_Window == NULL)
      {
         std::cout << "Window could not be created! SDL Error: " << SDL_GetError();
      }
      else 
      {
         /** 
      * 
      */
         m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
         if (m_Renderer == NULL)
         {
            std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError();
            SDL_DestroyWindow(m_Window);
            SDL_Quit();
            return;
         }
      }
   }
   // Destructor
   ~SDLApp()
   {
      /**
      * We destroy our window. We are passing in the pointer that
      *  points to the memory allocated by the 'SDL_CreateWindow'
      *  function. Remember, this is a 'C-Style' API, we don't have
      *  destructors!
      */
      SDL_DestroyWindow(m_Window);
   }

   // Handle Events
   void SetEventCallback(std::function<void(void)> func)
   {
      m_EventCallback = func;
   }

   // Handle Render
   void SetRenderCallback(std::function<void(void)> func)
   {
      m_RenderCallback = func;

      

   }

   // Loop our application
   void RunLoop()
   {
      while (m_GameIsRunning)
      {
         // Handle events first
         m_EventCallback();
         // Then handle our rendering (6:41)
         m_RenderCallback();
      }

   }

private:
   // Pointer to our SDL Window
   SDL_Window* m_Window = nullptr;
   // Pointer to our SDL Renderer
   SDL_Renderer* m_Renderer = nullptr;
   // Infinite loop for our application
   bool m_GameIsRunning = true;
   
   // Store our callback functions (5:20)
   std::function<void(void)> m_EventCallback;
   std::function<void(void)> m_RenderCallback;
   

};

#endif // !SDLAPP_H