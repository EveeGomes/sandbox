#ifndef BALL_H
#define BALL_H

// Will have to include SDL here too...
#include "SDL.h"

class Ball
{
//private:
public:
   float m_CenterX, m_CenterY; // drawing from center to the border reaching it through the radius
   float m_Radius;
   float m_SpeedX, m_SpeedY;
   SDL_Renderer* m_Renderer = nullptr;

   void DrawFilledCircle(int centerX, int centerY, int Radius);

public:
   Ball() = default;
   // Set the renderer coming from Main in the constructor (where we instantiate an object of this class)
   Ball(int centerX, int centerY, int Radius, SDL_Renderer* Renderer);
   void SetSpeeds(float SpeedX, float SpeedY);

   void Draw();

   // Getters
   inline float GetCenterX() { return m_CenterX; }
   inline float GetCenterY() { return m_CenterY; }
   inline float GetRadius() { return m_Radius; }
};

#endif // !BALL_H