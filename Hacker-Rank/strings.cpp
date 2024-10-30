#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */

   std::string a{};
   std::string b{};

   std::cin >> a;
   std::cin >> b;

   // print two space-separated ints representing 
   //  the length of a and b respectively
   std::cout
      << a.size()
      << " "
      << b.size()
      << std::endl;

   // print a concatenated string (a + b)
   std::cout << a + b << std::endl;

   // print two strings space-separated similar to
   //  a and b, the only difference is their first
   //  characters are swapped
   char temp{};
   temp = a[0];
   a[0] = b[0];
   b[0] = temp;
   std::cout << a << " " << b << std::endl;


   return 0;
}
