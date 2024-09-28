#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// Create a local vector
// Add params to the vector
// Check the max element
// Retrieve that elem and return

int max_of_four(int a, int b, int c, int d)
{
   int intParams[] = { a, b, c, d };
   std::vector<int> localVec{ intParams, intParams + sizeof(intParams) / sizeof(int) };

   return *std::max_element(localVec.begin(), localVec.end());
}

int main() {
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */

   int a, b, c, d = 0;
   std::cin >> a;
   std::cin >> b;
   std::cin >> c;
   std::cin >> d;

   int maxInt = max_of_four(a, b, c, d);
   std::cout << maxInt;

   return 0;
}