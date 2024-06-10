#include "Ball.h"
//#include "SDL.h"

void Ball::Draw()
{
   // Use the function above! It's a modified function of the midpoint circle algorithm. 
   // It'll draw horizontal lines (or vertical) between pairs of points filling the space inside the circle.
   DrawFilledCircle(renderer, (int)x, (int)y, radius);
}

void DrawFilledCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
   int x = radius;
   int y = 0;
   int err = 1 - x;

   while (x >= y) {
      SDL_RenderDrawLine(renderer, centerX - x, centerY + y, centerX + x, centerY + y);
      SDL_RenderDrawLine(renderer, centerX - y, centerY + x, centerX + y, centerY + x);
      SDL_RenderDrawLine(renderer, centerX - x, centerY - y, centerX + x, centerY - y);
      SDL_RenderDrawLine(renderer, centerX - y, centerY - x, centerX + y, centerY - x);

      y++;

      if (err < 0) {
         err += 2 * y + 1;
      }
      else {
         x--;
         err += 2 * (y - x + 1);
      }
   }
}
