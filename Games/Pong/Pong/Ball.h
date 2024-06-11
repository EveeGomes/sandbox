#ifndef BALL_H
#define BALL_H


// Will have to include SDL here too...
#include "SDL.h"

class Ball
{
private:
   float m_CenterX, m_CenterY; // drawing from center to the border reaching it through the radius
   float m_Radius;
   float m_SpeedX, m_SpeedY;
   SDL_Renderer* m_Renderer = nullptr;

   void DrawFilledCircle(int centerX, int centerY, int Radius);

public:
   Ball() = default;
   // Set the renderer coming from Main in the constructor (where we instantiate an object of this class)
   Ball(int centerX, int centerY, int Radius, SDL_Renderer* Renderer);

   void Draw();

};

#endif // !BALL_H