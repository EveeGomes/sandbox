#include "Matrix.h"

int main()
{
   std::fstream fin("matrix.txt");

   Matrix<int> A{3};

   fin >> A;
   std::cout << A;

   Matrix<int> C{A}; // copy constructor
   std::cout << std::endl;
   std::cout << C;

   Matrix<int> B = C; // assignment operator
   std::cout << std::endl;
   std::cout << B;
   

   fin.close();

   return 0;
}