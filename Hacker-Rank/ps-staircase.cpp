#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void staircase(int n) {
   // use std::width() and std::right to print
   // the first print is like n = 1, and the right-aligned as n - 1
   // then, print # 
   // the second, is like n = 2, right-aligned n - 2
   // so, have a variable, say begin, to start at 1 and increase 
   //  until it reaches the value of n
   // to print, use std::width(n - begin)

   // print height times. So while (height > 0), print
   // for each print, each line, we'll have the std::width(width - begin)
   // each line, print # begin times
   // begin is updated outside the loop

   int begin = 0; // start at 0 so the std::width works well?
   int height = n;
   int width = n;
   //int i = 0;
   while (height > 0)
   {
      //std::cout << begin;
      // setup the width outside the loop
      std::cout.width(width - begin); // 6-1, 6-2, 6-3, 6-4, 6-5, 6-6 -> so, change begin to start at 0 and then after setting this line, increase begin
      begin++;
      for (int i = 0; i < begin; i++)
      {
         //std::cout.width(width - begin);
         std::cout << std::right << "#";
         //begin--;
         //std::cout << begin << "\n";
      }
      std::cout << std::endl;
      //begin++;
      height--; // return to be 1
   }
}

int main()
{
   string n_temp;
   getline(cin, n_temp);

   int n = stoi(ltrim(rtrim(n_temp)));

   staircase(n);

   return 0;
}

string ltrim(const string& str) {
   string s(str);

   s.erase(
      s.begin(),
      find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
   );

   return s;
}

string rtrim(const string& str) {
   string s(str);

   s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end()
   );

   return s;
}
