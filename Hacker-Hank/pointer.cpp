
/** 
* Function Description

   Complete the update function in the editor below.

   update has the following parameters:

   int *a: an integer
   int *b: an integer
   Returns

   The function is declared with a void return type, so there is no value to return. Modify the values in memory so that  contains their sum and  contains their absoluted difference.

   a = a + b
   b = |a - b|

   Input Format

   Input will contain two integers, a and b, separated by a newline.

   Sample Input
   4
   5

   Sample Output
   9
   1
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void modifyInts(int* a, int* b)
{
   // store the sum of a + b in a
   // HOWEVER, these will also be used for finding the absolute difference!
   // So, have an temp int to store the sum, as well as the abs diff and
   //  only at the end, set these values to a and b!

   int sum = (*a) + (*b);
   //*a = (*a) + (*b);

   // store the absolute difference between a - b in b
   int absDiff = std::abs(*a - *b);
   //*b = std::abs(*a - *b);
   //*b = std::max(*a, *b) - std::min(*a, *b);

   *a = sum;
   *b = absDiff;
}

int main() {
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */

   int a = 0;
   int b = 0;
   int* aPtr = &a;
   int* bPtr = &b;

   std::cin >> a;
   std::cin >> b;

   modifyInts(aPtr, bPtr);

   std::cout << *aPtr << std::endl;
   std::cout << *bPtr << std::endl;

   return 0;
}
