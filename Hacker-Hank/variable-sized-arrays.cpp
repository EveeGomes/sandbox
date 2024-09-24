/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

int main()
{
   int n; // size of first array
   int q; // queries

   int k; // size of second/inner array
   int i = -1; // index of first array
   int j = -1; // index of second array

   std::cout << "Enter n: "; // remove this in HackerRank
   std::cin >> n;
   std::cout << "Enter q: "; // remove this in HackerRank
   std::cin >> q;

   /*
   // i and j should receive input and used according to the value of q
   std::cout << "Enter i: "; // remove this in HackerRank
   std::cin >> i;
   std::cout << "Enter j: "; // remove this in HackerRank
   std::cin >> j;
   */

   std::vector<std::vector<int>> a;
   //a.resize(n);

   while (n > 0)
   {
      int value;
      std::cout << "Enter size of arr: "; // remove this in HackerRank
      std::cin >> k;

      std::vector<int> arr;

      for (int m = 0; m < k; m++)
      {
         std::cout << "Enter elements: "; // remove this in HackerRank
         std::cin >> value;
         arr.push_back(value);
      }

      // Add a vector to a vector of vector
      a.push_back(arr);

      n--;
   }
   //std::cout << a.size();

   // print an element from array at i. Say i = 0. So we need the array located at a[0].
   // 1. retrieve that array from a
   // 2. copy the content to another temp array/vector
   // 3. print out the element at j from that array
   /*
   std::vector<int> tempArr {a[i]}; // i = 0
   std::cout << "Element at i = 0, j = 2 is: " << tempArr[j]; // j = 1
   */

   //// or: 
   //std::cout << a[i][j]; // better

   // Now, add that to a loop that depends on q value
   while (q > 0)
   {
      std::cout << "Enter i: "; // remove this in HackerRank
      std::cin >> i;
      std::cout << "Enter j: "; // remove this in HackerRank
      std::cin >> j;

      std::cout << a[i][j] << std::endl;
      q--;
   }

   return 0;
}