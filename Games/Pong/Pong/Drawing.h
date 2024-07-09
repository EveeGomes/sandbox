#ifndef DRAWING_H
#define DRAWING_H

#include "SDL.h"

class Ball;

class Drawing
{
   void DrawFilledCircle(Ball* BallObj, SDL_Renderer* Renderer);
};

#endif // !DRAWING_H

