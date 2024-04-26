#include <iostream>
#include <iomanip>

struct MyVector2D
{
   int m_x = 0;
   int m_y = 0;

   MyVector2D(int x, int y) 
      : m_x(x),
        m_y(y) {}

   MyVector2D Addition(MyVector2D otherVector)
   {
      MyVector2D FinalVec{ m_x + otherVector.m_x, m_y + otherVector.m_y };
      return FinalVec;
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


   }
};

int main()
{
   MyVector2D Vec1{ 1, 2 };
   MyVector2D Vec2{ 2, 4 };

   Vec1.PrintVectorValues();
   Vec2.PrintVectorValues();

   std::cout << std::endl;
   Vec2.PrintLocation();
   std::cout << std::endl;
   std::cout << std::endl;

   MyVector2D Vec3 = Vec1.Addition(Vec2);
   Vec3.PrintVectorValues();

   

   return 0;
}