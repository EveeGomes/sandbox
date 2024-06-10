#pragma once

// Will have to include SDL here too...
#include "SDL.h"

class Ball
{

   float x, y;
   float speedX, speedY;
   float radius;

   void Draw();

   void DrawFilledCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius);

};

