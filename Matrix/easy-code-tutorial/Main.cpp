#include "Matrix.h"

int main()
{
   std::fstream fin("matrix.txt");

   Matrix<int> A{2, 3};
   fin >> A;
   std::cout << A << std::endl;

   Matrix<int> B{3, 1};
   fin >> B;
   std::cout << B << std::endl;

   Matrix<int> D = A * B;
   std::cout << "\n" << D;

   fin.close();

   return 0;
}