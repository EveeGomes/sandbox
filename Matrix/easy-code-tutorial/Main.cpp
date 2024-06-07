#include "Matrix.h"

int main()
{
   std::fstream fin("matrix.txt");

   Matrix<int> A{2};

   fin >> A;
   std::cout << A;

   Matrix<int> B{2}; // assignment operator
   std::cin >> B;
   std::cout << std::endl;
   std::cout << B;

   Matrix<int> D = A * B;
   std::cout << "\n" << D;



   fin.close();

   return 0;
}