
/** 
* Function Description

   You will be given an array of N integers and you have to print the integers in the reverse order.

   Input Format:
   The first line of the input contains N, where N is the number of integers. The next line contains N space-separated integers.

   Constraints:
   1 <= N <= 1000
   1 <= A|i| <= 10000, where A|i| is the ith integer in the array.

   Output Format:
   Print the N integers of the array in the reverse order, space-separated on a single line.

   Sample Input
   4
   1 4 3 2

   Sample Output
   2 3 4 1
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */

   //int n;
   //std::cout << "Enter the array size: "; // this actually showed the output! 2 3 4 1 in HackerRank. Comment it out and it'll work!
   //std::cin >> n;

   //int intArr[n]; // it'll work in HackerRank, but not here because of VLAs (allowed in GCC, used in HackerRank)

   //for (int i = 0; i < n; i++)
   //{
   //   std::cin >> intArr[i];
   //}

   //for (int i = n - 1; i >= 0; i--)
   //{
   //   std::cout << intArr[i] << " ";
   //}
   
      
   /** The following will work in both HackerRank and VS! */
   //std::vector<int> intVect{1, 4, 3, 2};
   int size = 0;
   std::cout << "Enter the array size: "; // remove this line in HackerRank!
   std::cin >> size;

   std::vector<int> intVect(size); // use () instead of {}

   for (int i = 0; i < size; i++)
   {
      std::cin >> intVect[i];
   }

   std::cout << intVect.size() << std::endl; // remove this line in HackerRank!
   for (int i = intVect.size() - 1; i >= 0; i--)
   {
      std::cout << intVect[i] << " ";
   }
   
   return 0;
}