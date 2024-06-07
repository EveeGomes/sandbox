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

   Matrix<int> D{2}; // can't be float...
   std::cin >> D;
   std::cout << "\n" << D;

   if (A == B) std::cout << "Same!\n";
   if (A != D) std::cout << "Not the same!";

   fin.close();

   return 0;
}