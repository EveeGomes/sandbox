#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
using namespace std;


int main() {
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */

   // receive the number of queries from user
   int Q{};
   std::cin >> Q;

   // if type == 1, user enters a string and an int,
   //  which represent name and mark of a student
   // if type == 2, user enters just a string, name
   // if type == 3, user enters just a string, name

   // for the output, only when type == 3, print the
   //  marks given to the student

   int type{};
   // have a map to associate the student's name and marks
   std::map<std::string, int> studentInfo;

   std::string name{};
   int mark{};

   std::stringstream ssInput{};
   std::string inputString{};
   char discardSpace{};

   while (Q > 0)
   {
      //std::cin >> inputString;
      // get rid of the newline from the previous input but using std::ws together with std::cin
      std::getline(std::cin >> std::ws, inputString);
      ssInput.str(inputString);
      ssInput >> type;
      std::cout << "Q > 0; type is: " << type << std::endl;

      if (type == 1)
      {
         //getline(std::cin, name);
         // std::cin >> mark;

         ssInput >> name >> mark;
         std::cout << name << " " << mark;
      }
      Q--;
   }

   return 0;
}
