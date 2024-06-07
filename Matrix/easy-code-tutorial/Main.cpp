#include "Matrix.h"

int main()
{
   Matrix<int> A{ 2, 3 };

   std::cin >> A;
   std::cout << A;

   //Matrix<float> B{ 3 };

   //Matrix<int> C = A;

   return 0;
}