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
   std::map<std::string, std::vector<int>> studentInfo;

   std::string name{};
   int mark{};

   // get the input and transfer to a stringstream to parse it later!
   std::string inputString{};
   std::stringstream ssInput{};

   while (Q > 0)
   {
      // clear the string before reading a new input?
      inputString.clear();
      //std::cin >> inputString;
      // get rid of the newline from the previous input but using std::ws together with std::cin
      std::getline(std::cin >> std::ws, inputString);

      // clear and reset the stringstream before setting it with the content of the string
      ssInput.clear();
      ssInput.str("");
      ssInput.str(inputString);
      ssInput >> type;
      std::cout << "Q > 0; type is: " << type << std::endl;

      if (type == 1)
      {
         //getline(std::cin, name);
         // std::cin >> mark;

         ssInput >> name >> mark;

         // check if name already exists. If it does add the mark otherwise add a new element to the map
         auto nameItr = studentInfo.find(name);
         if (nameItr != studentInfo.end())
         {
            nameItr->second.push_back(mark);
         }
         else
         {
            //studentInfo.insert(std::pair<std::string, std::vector<int>>(name, std::vector<int>{mark}));
            studentInfo.insert(std::make_pair(name, std::vector<int>{mark}));
         }
         

         /*studentInfo[name] = mark;*/

         //std::cout << name << " " << mark;
      }
      if (type == 2)
      {
         // erase the marks of the students whose name is given
         ssInput >> name;
         if (studentInfo.find(name) != studentInfo.end())
         {
            studentInfo.find(name)->second.clear();
         }
      }
      if (type == 3)
      {
         // print the sum of marks of the students whose name is given
         ssInput >> name;
         if (studentInfo.find(name) != studentInfo.end())
         {
            for (const int& studentMark : studentInfo.find(name)->second)
            {
               std::cout << studentMark << std::endl;
            }
         }
      }

      Q--;
   }

   return 0;
}
