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

   void PrintVector()
   {
      // Need like a table to simulate coordinates in order to draw something?
      //std::cout << std::setfill('/') << std::setw(m_x + m_y) << "";
      //std::cout << std::setfill('_') << std::setw(m_x) << "";
      //std::cout << std::setfill('|') << std::setw(m_y) << "";

      //int padding = m_x + 1;
      int padding = m_x;

      //std::cout << "|" << "\n";
      //m_y--;

      while (m_y > 0)
      {
         if (m_y == 1)
         {
            std::cout << std::setw(padding) << "|";
         }
         else
         {
            std::cout << std::setw(padding) << "|" << "\n";
            //std::cout << std::setw(padding) << "|\n";
         }

         m_y--;
      }

      while (m_x > 0)
      {
         std::cout << "_";
         m_x--;
      }

   }
};

int main()
{
   MyVector2D Vec1{ 1, 2 };
   MyVector2D Vec2{ 2, 4 };

   Vec1.PrintVectorValues();
   Vec2.PrintVectorValues();

   std::cout << std::endl;
   Vec2.PrintVector();
   std::cout << std::endl;
   std::cout << std::endl;

   MyVector2D Vec3 = Vec1.Addition(Vec2);
   Vec3.PrintVectorValues();

   

   return 0;
}