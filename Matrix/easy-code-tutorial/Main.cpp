#include "Matrix.h"

int main()
{
   std::fstream fin("matrix.txt");

   Matrix<int> A{3};

   fin >> A;
   std::cout << A;

   //Matrix<float> B{ 3 };

   //Matrix<int> C = A;

   fin.close();

   return 0;
}