#include "Matrix.h"

int main()
{
   Matrix<int> A{ 2, 3 };

   Matrix<float> B{ 3 };

   Matrix<int> C = A;

   return 0;
}