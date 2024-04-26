#include <iostream>
#include <iomanip>
#include <math.h>

struct MyVector2D
{
   float m_x = 0.f;
   float m_y = 0.f;

   MyVector2D(float x, float y) 
      : m_x(x),
        m_y(y) {}

   MyVector2D Addition(MyVector2D otherVector)
   {
      MyVector2D FinalVec{ m_x + otherVector.m_x, m_y + otherVector.m_y };
      return FinalVec;
   }

   float VectorMagnitude() // or vector length
   {
      float Magnitude = hypot(m_x, m_y);
      return Magnitude;
   }

   void PrintVectorValues()
   {
      std::cout << "Vector x: " << m_x << " | y: " << m_y << std::endl;
   }

   void PrintLocation()
   {
      // Need a origin location like the world starting point. Then, from that location, set the x "padding/width" and y "height"

      /** *
      * 
      * ^ y
      * |
      * |
      * |    * (x, y)
      * |____________> x
      * 
      * 
      *             ^ y
      *             |
      *             |
      *             |
      *  ___________|___________>x
      *             |
      *   (x, y) *  |   
      *             |
      **
      * 
      * 
      * So, have a height that could represent the y axis and a width that could represent the x
      * Those values "should" range from - to +, but in a window there's no way to have a negative x or negative y, right?
      * Instead, the movement is to add +1 if moving right or adding -1 if moving left.
      * But, y is inverted? To go down we add +1 and to go up we add -1 until it reaches 0 again. 
      * (0, 0) in a window is the top left corner!
      * 
      */
      
      // A positional vector is the one that origins from the world origin, or coordinate 0,0 (or 0, 0 ,0 for 3D), and goes until the
      //    the point where the actor is in the world for example.

   }
};

int main()
{
   MyVector2D Vec1{ 1.f, 2.f };
   MyVector2D Vec2{ 2.f, 4.f };

   Vec1.PrintVectorValues();
   Vec2.PrintVectorValues();
   std::cout << "Vec1 length: " << Vec1.VectorMagnitude() << std::endl;

   std::cout << std::endl;
   Vec2.PrintLocation();
   std::cout << std::endl;
   std::cout << std::endl;

   MyVector2D Vec3 = Vec1.Addition(Vec2);
   Vec3.PrintVectorValues();

   

   return 0;
}