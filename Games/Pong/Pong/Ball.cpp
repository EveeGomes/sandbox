#include "Ball.h"

Ball::Ball(int centerX, int centerY, int Radius, SDL_Renderer* Renderer)
   : m_CenterX(centerX), m_CenterY(centerY), m_Radius(Radius), m_Renderer(Renderer) {}

void Ball::SetSpeeds(float SpeedX, float SpeedY)
{
   m_SpeedX = SpeedX;
   m_SpeedY = SpeedY;
}

void Ball::DrawFilledCircle(int centerX, int centerY, int Radius) {
   int x = Radius;
   int y = 0;
   int err = 1 - x;

   while (x >= y) {
      SDL_RenderDrawLine(m_Renderer, centerX - x, centerY + y, centerX + x, centerY + y);
      SDL_RenderDrawLine(m_Renderer, centerX - y, centerY + x, centerX + y, centerY + x);
      SDL_RenderDrawLine(m_Renderer, centerX - x, centerY - y, centerX + x, centerY - y);
      SDL_RenderDrawLine(m_Renderer, centerX - y, centerY - x, centerX + y, centerY - x);

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

void Ball::Draw()
{
   // Use the function above! It's a modified function of the midpoint circle algorithm. 
   // It'll draw horizontal lines (or vertical) between pairs of points filling the space inside the circle.

   DrawFilledCircle((int)m_CenterX, (int)m_CenterY, m_Radius); // No need to pass a renderer because there's a m_Renderer member variable that can be used in the DrawFilledCircle!
}