#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */

   // get number of queries and store in Q, integer
   // next input: y and x, integers
   // y: the type of query, x: the value to add to the set
   // if type == 1: add 
   // if type == 2: delete if it's present in the set
   // if type == 3: print Yes if exist, otherwise No

   int Q{};
   std::cin >> Q;

   int type{};
   int x{};
   std::set<int> ints{};

   while (Q > 0)
   {
      std::cin >> type >> x;
      if (type == 1)
      {
         ints.insert(x);
      }
      if (type == 2)
      {
         if (ints.find(x) != ints.end())
         {
            ints.erase(x);
         }
      }
      if (type == 3)
      {
         if (ints.find(x) != ints.end())
         {
            std::cout << "Yes" << std::endl;
         }
         else
         {
            std::cout << "No" << std::endl;
         }
      }
      Q--;
   }

   return 0;
}
