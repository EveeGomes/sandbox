#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

std::vector<int> parseInts(std::string str)
{
   std::stringstream ss{};
   std::vector<int> vecInts{};
   int temp = 0;
   char ch{};

   ss.str(str);

   while (ss >> temp)
   {
      vecInts.push_back(temp);
      ss >> ch;
   }
   /*
   for (int intElm : vecInts)
   {
       std::cout << intElm << std::endl;
   }
   */
   return vecInts;
}


int main() {
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */

   std::string stringInput{};

   std::getline(std::cin, stringInput);

   std::vector<int> ints{};
   ints = parseInts(stringInput);

   for (int intElm : ints)
   {
      std::cout << intElm << std::endl;
   }

   return 0;
}
